#pragma once
#ifndef PART_DESIGN_H
#define PART_DESIGN_H
#include "design.h"
//�����ƻ��࣬����һ���������
class Part_Design : public Design {
public:
	Part_Design(string load):Load(load) {};
	virtual ~Part_Design() {};
	void setLoad(string str) { Load = str; }

protected:
	string Load;		//�غ����ʣ����غɻ��غɵ�
};

#endif 
