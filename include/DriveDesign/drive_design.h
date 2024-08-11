#pragma once
#ifndef DRIVE_DESIGN_H
#define DRIVE_DESIGN_H
#include "design.h"

class Drive_Design : public Design {			//传动设计
public:
	Drive_Design(){}
	virtual ~Drive_Design() {};					//又一个抽象基类
protected:
	int n = 970;								//小轮的转速
	int Lh = 60000;								//预计工作的时间
	double KV = 1.0;							//动载系数
	double T1 = 10000;							//小轮传递的转矩N mm
	double P = 11;								//输入功率kw
protected:
	void setP(double val) { P = val; }			//修改功率
	void setn(double val) { n = val; }			//修改小轮转速
	void setT(double val) { T1 = val; }			//修改转矩
	void setKV(double val) { KV = val; }		//动载系数
	void setLh(double val) { Lh = val; }		//工作时长

	void setDrive(ostream& os);					//传动参数输入
};

#endif