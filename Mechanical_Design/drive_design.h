#pragma once
#ifndef DRIVE_DESIGN_H
#define DRIVE_DESIGN_H
#include "design.h"

class Drive_Design : public Design {	//传动设计
public:
	Drive_Design(){}
	virtual ~Drive_Design() {}; //又一个抽象基类
protected:
	int n = 970;        //小轮的转速
	int Lh = 10000;   //预计工作的时间
	double KV = 1.0; //动载系数
	double T1 = 10000; //小轮传递的转矩
	double P = 11;		//输入功率kw
};

#endif