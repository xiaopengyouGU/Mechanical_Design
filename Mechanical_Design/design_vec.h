#pragma once
#ifndef DESIGN_VEC_H
#define DESIGN_VEC_H
#include <vector>
//包含所有的具体设计类
#include "spur_gear_drive.h"
#include "bevel_gear_drive.h"

class Design_Vec {
public:
	Design_Vec() = default;	//默认构造函数
	Design_Vec(const std::vector<shared_ptr<Design>> &vec):VecPtr(vec){}
	Design_Vec(const Design_Vec& rhs):VecPtr(rhs.VecPtr){}
	Design_Vec& operator=(const Design_Vec& rhs) {	//重载赋值运算符
		VecPtr = rhs.VecPtr;
		return *this;
	}
	~Design_Vec() { std::cout << "完成所有设计!" << std::endl;}

	int getSize()const { return VecPtr.size(); }	//返回设计对象数目

	void addDesign(shared_ptr<Design> des);			//添加一个设计对象
	void deleteDesign(int pos);						//删除一个设计对象
	void showDesign(int pos);						//显示一个设计对象
	void showTotalDesign(bool b);					//显示所有设计对象，详细与否
	void deleteTotalDesign();						//删除所有设计对象
	
private:
	std::vector<shared_ptr<Design>> VecPtr;			//使用包含智能指针的容器
};

#endif
