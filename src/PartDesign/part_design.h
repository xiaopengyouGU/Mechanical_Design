#pragma once
#ifndef PART_DESIGN_H
#define PART_DESIGN_H
#include "design.h"
//零件设计基类，还是一个抽象基类
class Part_Design : public Design {
public:
	Part_Design(string load):Load(load) {};
	virtual ~Part_Design() {};
	void setLoad(string str) { Load = str; }

protected:
	string Load;		//载荷性质，静载荷或动载荷等
};

#endif 
