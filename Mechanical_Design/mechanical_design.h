#pragma once
#ifndef MECHANICAL_DESIGN_H
#define MECHANICAL_DESIGN_H
#include "design_vec.h"
#include "interaction.h"
//总体设计类
class Mechanical_Design {
public:
	Mechanical_Design() {
		vec = std::make_shared<Design_Vec>();
		Ite = std::make_shared<Interaction>();
		startDesign(std::cout);	//开始设计
	};
	~Mechanical_Design() {};
private:
	shared_ptr<Design_Vec> vec;		//设计表对象
	shared_ptr<Interaction> Ite;		//交互对象
	//每个零件处理自己的最终设计过程，Mechanical_Design只提供公共接口
	void startDesign(std::ostream& os);		//开始设计
	void startDriveDesign(std::ostream& os);//开始传动设计
	void startPartDesign(std::ostream& os);	//开始零件设计
};
#endif