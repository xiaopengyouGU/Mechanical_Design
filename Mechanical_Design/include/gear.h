#pragma once
#ifndef GEAR_H
#define GEAR_H
#include "part.h"
class Gear : public Part {	//���ü̳�
public:
	Gear(string mat,string hard):Part(mat,hard){}
	virtual ~Gear() {};
protected:		//�����̳�
	int Z = 0;      //����
	double B = 0.0;	//�ݿ�
	double d = 0;   //�ֶ�Բֱ��
	double m = 0.0;	//ģ��
	double a = 20; //ѹ���ǣ�ע�ⵥλ����
};

#endif