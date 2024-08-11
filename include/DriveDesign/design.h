#pragma once
#ifndef DESIGN_H
#define DESIGN_H
#include<memory>
#include<cmath>
#include<ctime>
#include<iostream>
#include"part.h"
using std::shared_ptr;									//ʹ������ָ�룬���ö�̬��
using std::iostream;
//�ܹ����ĸ����麯����Ҫ����ʵ��
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
	void setLevel(int val) { Level = val; }				//�趨��Ƶľ��ȵȼ�

	double Angle_To_Radian(double angle) { return angle / 180 * M_PI; }; //�ǶȻ���
protected:
	virtual void setDefault() = 0;						//Ĭ�ϲ������
	virtual void setUserChoice(std::ostream& os) = 0;	//���û�ѡ���Ĳ��������

	time_t timer = 0;
	int Num = 1;										//��Ʊ��
	int Level = 7;										//���ȵȼ�
	string Name = "���";								//�������
};
#endif