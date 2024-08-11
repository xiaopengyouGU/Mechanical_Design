#pragma once
#ifndef DESIGN_H
#define DESIGN_H
#include<memory>
#include<cmath>
#include<ctime>
#include<iostream>
#include"part.h"
using std::shared_ptr;									//使用智能指针，利用动态绑定
using std::iostream;
//总共有四个纯虚函数需要重新实现
class Design {
public:
	Design()noexcept{}
	virtual ~Design() {};
	virtual void setDesign(bool b) = 0;					//虚函数，开始设计
	virtual void showDesignInfo(ostream& os) = 0;		//显示设计信息

	int getNum() const { return Num; }					//返回设计编号
	string getName() const { return Name; }				//获取设计名称

	void setName(string str) { Name = str; }			//修改设计名称
	void setNum(int i) { Num = i; }						//设定设计编号
	void setLevel(int val) { Level = val; }				//设定设计的精度等级

	double Angle_To_Radian(double angle) { return angle / 180 * M_PI; }; //角度换算
protected:
	virtual void setDefault() = 0;						//默认参数设计
	virtual void setUserChoice(std::ostream& os) = 0;	//按用户选定的参数来设计

	time_t timer = 0;
	int Num = 1;										//设计编号
	int Level = 7;										//精度等级
	string Name = "设计";								//设计名称
};
#endif