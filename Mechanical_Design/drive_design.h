#pragma once
#ifndef DRIVE_DESIGN_H
#define DRIVE_DESIGN_H
#include "design.h"

class Drive_Design : public Design {	//�������
public:
	Drive_Design(){}
	virtual ~Drive_Design() {}; //��һ���������
protected:
	int n = 970;        //С�ֵ�ת��
	int Lh = 10000;   //Ԥ�ƹ�����ʱ��
	double KV = 1.0; //����ϵ��
	double T1 = 10000; //С�ִ��ݵ�ת��
	double P = 11;		//���빦��kw
};

#endif