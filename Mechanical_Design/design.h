#pragma once
#ifndef DESIGN_H
#define DESIGN_H
#define M_PI       3.14159265358979323846 //����Pi
#include<memory>
#include<cmath>
#include<ctime>
#include<iostream>
#include"part.h"
using std::shared_ptr;  //ʹ������ָ�룬���ö�̬��
using std::iostream;
class Design {
public:
	Design()noexcept{}
	virtual ~Design() {};
	virtual void setDesign() = 0;		//�麯������ʼ���
	void setNum(int i) { Num = i; }
	int getNum() const { return Num; }	//������Ʊ��
	string getName() const { return Name; } //��ȡ�������
	virtual void showDesignInfo(ostream& os) = 0;
protected:
	time_t timer = 0;
	int Num = 1;		//��Ʊ��
	string Name = "���"; //�������
};
#endif