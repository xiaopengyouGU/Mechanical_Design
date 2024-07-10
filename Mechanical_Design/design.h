#pragma once
#ifndef DESIGN_H
#define DESIGN_H
#define M_PI       3.14159265358979323846 //定义Pi
#include<memory>
#include<cmath>
#include<ctime>
#include<iostream>
#include"part.h"
using std::shared_ptr;  //使用智能指针，利用动态绑定
using std::iostream;
class Design {
public:
	Design()noexcept{}
	virtual ~Design() {};
	virtual void setDesign() = 0;		//虚函数，开始设计
	void setNum(int i) { Num = i; }
	int getNum() const { return Num; }	//返回设计编号
	string getName() const { return Name; } //获取设计名称
	virtual void showDesignInfo(ostream& os) = 0;
protected:
	time_t timer = 0;
	int Num = 1;		//设计编号
	string Name = "设计"; //设计名称
};
#endif