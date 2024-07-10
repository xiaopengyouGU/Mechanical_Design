#pragma once
#ifndef MECHANICAL_DESIGN_H
#define MECHANICAL_DESIGN_H
#include "design_vec.h"
#include "interaction.h"
//���������
class Mechanical_Design {
public:
	Mechanical_Design() {
		vec = std::make_shared<Design_Vec>();
		Ite = std::make_shared<Interaction>();
		startDesign(std::cout);	//��ʼ���
	};
	~Mechanical_Design() {};
private:
	shared_ptr<Design_Vec> vec;		//��Ʊ����
	shared_ptr<Interaction> Ite;		//��������
	//ÿ����������Լ���������ƹ��̣�Mechanical_Designֻ�ṩ�����ӿ�
	void startDesign(std::ostream& os);		//��ʼ���
	void startDriveDesign(std::ostream& os);//��ʼ�������
	void startPartDesign(std::ostream& os);	//��ʼ������
};
#endif