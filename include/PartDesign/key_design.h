#pragma once
#ifndef KEY_DESIGN_H
#define KEY_DESIGN_H
#include "part_design.h"
#include "key.h"
//键的设计
class Key_Design : public Part_Design {
public:
	Key_Design(bool b = true, string load = "静载荷") :Part_Design(load) {
		setDesign(b);							//开始设计
	}
	~Key_Design() {};
	void showDesignInfo(ostream& os) override;	//
	void setDesign(bool b) override;			//重载
private:
	void setDefault() override;
	void setUserChoice(ostream&os) override;	//用户手动操作
	void testStrength(ostream& os) ;			//强度校核
	void setKeybandh(ostream&os);				//确定键的宽度和高度,输出键的长度范围
	void showPossibleL(ostream& os);			//输出键的长度系列

	void setp(double val) { p = val; }
	void setbs(double val) { bs = val;}
	void setT(double val) { T = val; }
	void setb(double val) { b = val; }
	void setd(double val) { d = val; }

	shared_ptr<Key> part;						//零件对象
	double p;									//许用应力,动连接时才有
	double bs = 110;							//许用挤压应力,默认静连接，轴和毂都是钢
	double T = 2200;							//须传递的转矩 N m
	double b = 100;								//轮毂的宽度
	double d = 70;								//轴的直径
};

#endif