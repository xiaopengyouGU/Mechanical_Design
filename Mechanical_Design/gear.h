#pragma once
#ifndef GEAR_H
#define GEAR_H
#define HA  1
#define C 0.25								//定义两个系数
#include "part.h"
class Gear : public Part {	
public:
	Gear(string mat,string hard):Part(mat,hard){}
	Gear(string mat,string hard,double oh, double of,int z,double P = 0):Part(mat,hard),OH(oh),OF(of),
		Z(z),p(P){}
	virtual ~Gear() {};						//虚函数
	//参数获取
	int getZ() const { return Z; }          //获取齿数
	double geta() const { return a; }		//获取压力角
	double getOH() const { return OH; }     //获取接触疲劳极限
	double getOF() const { return OF; }		//获取弯曲疲劳极限
	double getB() const { return B; }       //获取齿宽
	double getm() const { return m; }		//获取模数
	double getd() const { return d; }		//获取分度圆直径
	double getp() const { return p; }
	string getRot() const { return Rot; }
	//参数设置
	void setZ(int z) { Z = z; }
	void seta(double A) { a = A; }
	void setOH(double val) { OH = val; }
	void setOF(double val) { OF = val; }
	void setm(double val) { m = val; }
	void setB(double val) { B = val; }
	void setd(double val) { d = val; }
	void setp(double val) { p = val; }
	void setRot(string str) { Rot = str; }

protected:									//保护继承
	int Z = 21;								//齿数
	double B = 10;							//宽度
	double d = 10;							//分度圆半径
	double m = 4;							//模数
	double a = 20;							//压力角
	double p = 0;							//螺旋角,
	string Rot = "右旋";					//旋向
	double OH = 300;						//接触疲劳极限
	double OF = 300;						//弯曲疲劳极限,注意对称循环时为70%
};

#endif