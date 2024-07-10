#pragma once
#ifndef GEAR_DRIVE_H
#define GERA_DRIVE_H
#include "drive_design.h"
#include "gear.h"
//开始设计齿轮传动
class Gear_Drive : public Drive_Design {
public:
	Gear_Drive(shared_ptr<Gear> p1 = nullptr, shared_ptr<Gear> p2 = nullptr)noexcept :
		Drive_Design(), part1(p1), part2(p2) {
	}	//几何尺寸计算}
	virtual ~Gear_Drive() {}; //又是一个抽象基类
protected:
	shared_ptr<Gear> part1;
	shared_ptr<Gear> part2;
	double e = 0; //重合度
	double u = 3.2; //传动比
	//载荷系数K = KA*KV*Ka*Kb
	double K = 1;
	double KT = 1.3;		//试算系数
	double KA = 1.0; //使用系数
	double KFa = 1.2; //齿间载荷分配系数
	double KFb = 1.2; //齿向载荷分配系数
	double KHa = 1.2;
	double KHb = 1.2; //接触疲劳对应的
	//齿轮的受力分析
	double Ft1 = 0; //圆周力 = 2*T1/d1
	double Fr1 = 0; //径向力 Ft1*tan(a)
	double Fn1 = 0; //名义法向力 Ft1/cos(a)
	//齿根弯曲疲劳强度
	double Ye = 0;  //重合度系数
	double YFa = 0; //齿形系数，只与轮廓形状有关
	double YSa = 0; //应力修正系数
	//齿面接触疲劳强度
	double ZE = 189.8; //弹性影响系数
	double Ze = 0;     //接触疲劳强度的重合度系数
	double ZH = 0;		//区域系数
	//疲劳极限
	double OF = 0;		//弯曲极限
	double OH = 0;		//疲劳极限
	double SF = 1.5;   //弯曲安全系数
	double SH = 1.2;   //接触安全系数
	//
	double KFN1 = 0.88;    //寿命系数
	double KFN2 = 0.91;		//
	double KHN1 = 0;
	double KHN2 = 0;
	int j = 1;        //齿轮每转一圈时同一齿面的啮合齿数
	double N = 0;        //工作应力循环次数
	double q = 1;        //宽度系数
	double dt = 0;
	double mt = 0;
	double a = 100; //中心距
	//弯曲和接触疲劳强度设计
	virtual void Bend_Fatigue_Design();
	virtual void Contact_Fatigue_Design();

protected:
	double Angle_To_Radian(double angle) { return angle / 180 * M_PI; }; //角度换算
	virtual void sete(int z1, int z2, double a, double p = 0);					//设置重合度,为虚函数
	virtual void setYe() { Ye = 0.25 + 0.75 / e; };					//设置重合度系数,也为虚函数
	void setOH(double OH1, double OH2);					//设置接触疲劳极限
	void setOF(double& OF1, double& OF2);					//设置弯曲疲劳极限,用引用
	virtual void setTrialDiameter(); //获取试算直径，按接触强度,为虚函数
	virtual void setTrialModulus(double OF1,double OF2,double z1,double p = 0);  //获取试算模数，按弯曲强度//获取弯曲疲劳极限
	virtual void setTriE(double a,double p = 0);  //三个E常数的处理,为虚函数
	void setFourK(bool b,double v1);		//四个K常数的处理
	void setdt() { dt = dt * pow(K / KT, 1.0 / 3); }				//调整分度圆直径
	void setmt() {
		mt = mt * pow(K / KT, 1.0 / 3);	//直接用弯曲疲劳的计算出的模数
		mt = round(mt);
	};																//调整模数
	virtual void setGear(double z1);			//设置齿轮的参数
	virtual void setDefault() = 0;					//默认参数设计
	virtual void setUserChoice() {};				//按用户选定的参数来设计

	void setKHaandKFa(double d);					//设置KHa和KFa参数
	void setKA(double val = 1.0) { KA = 1.0; };
	void setKHN(double val1 = 0.88, double val2 = 0.91) { KHN1 = val1, KHN2 = val2; }
	void setKFN(double val1 = 0.85, double val2 = 0.88) { KFN1 = val1, KFN2 = val2; }
	void setSF(double val = 1.4) { SF = val; }
	void setSH(double val = 1.0) { SH = val; }
	void setKHbandKFb(double val, double val2) { KHb = val, KFb = val2; }
	void setKV(double val) { KV = val; }
	void setP(double val) { P = val; } //修改功率
	void setn(double val) { n = val; }	//修改小轮转速
	void setT(double val) { T1 = val; } //修改转矩
	void setK(double val) { K = val; }
	void setu(double val) { u = val; }	//修改传动比
	void setq(double val) { q = val; }	//修改齿宽系数
	void setTwoY(double& YFa1, double& YSa1,double z1);			//自动利用插值法计算YFa, YSa
	//使用常量表达式和静态全局变量，优化内存
	constexpr static double TwoY[][2] = { {2.97,1.52},{2.91,1.53},{2.85,1.54},{2.80,1.55},
		{2.76,1.56},{2.72,1.57},{2.69,1.575},{2.65,1.58},{2.62,1.59},{2.60,1.595},{2.57,1.60},
		{2.55,1.61},{2.53,1.62},{2.52,1.625},{2.45,1.65},{2.40,1.67},{2.35,1.68},{2.32,1.70},
		{2.28,1.73},{2.24,1.75},{2.22,1.77},{2.20,1.78},{2.18,1.79},{2.14,1.83},{2.12,1.865},{2.06,1.97} };
};
#endif