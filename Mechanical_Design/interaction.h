#pragma once
#ifndef ITERACTION_H
#define ITERACTION_H
//������-��������
#include<iostream>
class Interaction {
public:
	Interaction() {}								
	~Interaction() {}

	void setIni(std::ostream& os);					//���ó�ʼ������
	void InterationOfTotal(std::ostream& os);		//����ƽ���Ľ���
	void InterationOfDriveDesign(std::ostream& os);	//������ƽ���Ľ���
	void InterationOfPartDesign(std::ostream& os);	//�����ƽ���Ľ���
	void InterationOfGearDrive(std::ostream& os);	//���ִ�����ƽ���
	void InterationOfKey(std::ostream& os);			//����ƽ���
	void InterationOfAxle(std::ostream& os);		//����ƽ���
	void InterationOfInfo(std::ostream& os);		//��ʾ�����Ϣ
	//�������ֵ���ƽ���...
	char getGearDrive() const { return chGearDrive; }
	char getAxle() const { return chAxle; }
	char getTotal() const { return chTotal; }
	char getDrive() const { return chDrive; }
	char getPart() const { return chPart; }			
	char getShow()const { return chShow; }

	void setTotal(char ch) { chTotal = ch;}			
	void setDrive(char ch) { chDrive = ch; }
	void setPart(char ch) { chPart = ch; }
	void setGearDrive(char ch) { chGearDrive = ch; }
	void setKey(char ch) { chKey = ch; }
	void setShow(char ch) { chShow = ch; }
private:
	char chTotal;									//����ѡ��
	char chDrive;									//����ѡ��
	char chPart;									//���ѡ��
	char chGearDrive;								//���ִ���
	char chKey;										//�������
	char chAxle;									//������
	char chShow;									//�����Ϣ
};

#endif
