#pragma once
#ifndef DRIVE_DESIGN_H
#define DRIVE_DESIGN_H
#include "design.h"

class Drive_Design : public Design {	//�������
public:
	Drive_Design(shared_ptr<Part> p1 = nullptr,shared_ptr<Part> p2 = nullptr) noexcept:
		part1(p1),part2(p2){}
	virtual ~Drive_Design() = 0; //��һ���������
protected:
	shared_ptr<Part> part1;
	shared_ptr<Part> part2;
	int n = 1800;        //С�ֵ�ת��
	int Lh = 10000;   //Ԥ�ƹ�����ʱ��
	double KV = 1.0; //����ϵ��
	double T1 = 100000; //С�ִ��ݵ�ת��
};

#endif