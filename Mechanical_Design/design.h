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
protected:
	time_t timer = 0;
	virtual void showDesignInfo(ostream& os) = 0;
};
#endif