#pragma once
#ifndef ITERACTION_H
#define ITERACTION_H
//������-��������
#include<iostream>
class Interaction {
public:
	Interaction() { }		//�����ʼ��
	~Interaction() { std::cout << "�ټ���" << std::endl; }
	void setIni(std::ostream& os);	//���ó�ʼ������
	void InterationOfTotal(std::ostream& os);		//����ƽ���Ľ���
	void InterationOfDriveDesign(std::ostream& os);	//������ƽ���Ľ���
	void InterationOfPartDesign(std::ostream& os);	//�����ƽ���Ľ���
	void InterationOfGearDrive(std::ostream& os);	//���ִ�����ƽ���
	void InterationOfKey(std::ostream& os);			//����ƽ���
	void InterationOfAxle(std::ostream& os);			//����ƽ���
	//�������ֵ���ƽ���...
	void setTotal(char ch) { chTotal = ch;}		//���ýӿڲ���
	void setDrive(char ch) { chDrive = ch; }
	void setPart(char ch) { chPart = ch; }
	void setGearDrive(char ch) { chGearDrive = ch; }
	void setKey(char ch) { chKey = ch; }
	char getGearDrive() const{ return chGearDrive; }

	char getAxle() const { return chAxle; }
	char getTotal() const { return chTotal; }
	char getDrive() const { return chDrive; }
	char getPart() const { return chPart; }	//���ݷ�װ
private:
	char chTotal;	//����ѡ��
	char chDrive; //����ѡ��
	char chPart;	//���ѡ��
	char chGearDrive;//���ִ���
	char chKey;      //�������
	char chAxle;	//������
};

#endif // !ITERACTION_H
