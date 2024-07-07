#pragma once
#ifndef GEAR_DRIVE_H
#define GERA_DRIVE_H
#include "drive_design.h"
#include "gear.h"
//开始设计齿轮传动
class Gear_Drive : public Drive_Design {
public:
	Gear_Drive(shared_ptr<Part> p1 = nullptr, shared_ptr<Part> p2 = nullptr)noexcept:
		Drive_Design(p1,p2){}
	virtual ~Gear_Drive() = 0; //又是一个抽象基类
protected:
	double e = 0; //重合度
	//载荷系数K = KA*KV*Ka*Kb
	double KA = 1.2; //使用系数
	double KFa = 1.2; //齿间载荷分配系数
	double KFb = 1.2; //齿向载荷分配系数
	double KHa = 1.2;
	double KFb = 1.2; //接触疲劳对应的
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
	double KN = 1;    //寿命系数
	int j = 1;        //齿轮每转一圈时同一齿面的啮合齿数
	int N = 0;        //工作应力循环次数
	//弯曲和接触疲劳强度设计
	virtual void Bend_Fatigue_Design();
	virtual void Contact_Fatigue_Design();
};
#endif