#pragma once
#ifndef ITERACTION_H
#define ITERACTION_H
//������-��������
#include<iostream>
class Iteraction {
public:
	Iteraction() { std::cout << "��ʼ������ƣ�" << std::endl;}
	~Iteraction() { std::cout << "�ټ���" << std::endl; }
	void setIni(std::ostream& os);	//���ó�ʼ������
	void setDriveDesign();	//����Ĳ�����Design_Vec����ʵ��
	void setPartDesign();	//������
	char getch1() const { return ch1; }
	char getch2() const { return ch2; }
	char getch3() const { return ch3; }	//���ݷ�װ
private:
	char ch1;	//
	char ch2; //����ѡ��
	char ch3;
};

#endif // !ITERACTION_H
