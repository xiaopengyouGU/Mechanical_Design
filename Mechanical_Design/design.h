#pragma once
#ifndef DESIGN_H
#define DESIGN_H
#define M_PI       3.14159265358979323846				//����Pi
#include<memory>
#include<cmath>
#include<ctime>
#include<iostream>
#include"part.h"
using std::shared_ptr;									//ʹ������ָ�룬���ö�̬��
using std::iostream;
class Design {
public:
	Design()noexcept{}
	virtual ~Design() {};
	virtual void setDesign(bool b) = 0;					//�麯������ʼ���
	virtual void showDesignInfo(ostream& os) = 0;		//��ʾ�����Ϣ

	int getNum() const { return Num; }					//������Ʊ��
	string getName() const { return Name; }				//��ȡ�������

	void setName(string str) { Name = str; }			//�޸��������
	void setNum(int i) { Num = i; }						//�趨��Ʊ��

	double Angle_To_Radian(double angle) { return angle / 180 * M_PI; }; //�ǶȻ���
protected:
	time_t timer = 0;
	int Num = 1;										//��Ʊ��
	string Name = "���";								//�������
};
#endif