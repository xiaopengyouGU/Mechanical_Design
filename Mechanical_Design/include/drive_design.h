#pragma once
#ifndef DRIVE_DESIGN_H
#define DRIVE_DESIGN_H
#include "design.h"

class Drive_Design : public Design {	//传动设计
public:
	Drive_Design(shared_ptr<Part> p1 = nullptr,shared_ptr<Part> p2 = nullptr) noexcept:
		part1(p1),part2(p2){}
	virtual ~Drive_Design() = 0; //又一个抽象基类
protected:
	shared_ptr<Part> part1;
	shared_ptr<Part> part2;
	int n = 1800;        //小轮的转速
	int Lh = 10000;   //预计工作的时间
	double KV = 1.0; //动载系数
	double T1 = 100000; //小轮传递的转矩
};

#endif