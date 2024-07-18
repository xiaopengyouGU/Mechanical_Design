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
	void InteractionOfTotal(std::ostream& os);		//����ƽ���Ľ���
	void InteractionOfDriveDesign(std::ostream& os);//������ƽ���Ľ���
	void InteractionOfPartDesign(std::ostream& os);	//�����ƽ���Ľ���
	void InteractionOfGearDrive(std::ostream& os);	//���ִ�����ƽ���
	void InteractionOfKey(std::ostream& os);		//����ƽ���
	void InteractionOfAxle(std::ostream& os);		//����ƽ���
	void InteractionOfBearing(std::ostream& os);	//��е�ǿ�����
	void InteractionOfChainDrive(std::ostream& os);	//������
	void InteractionOfBeltDrive(std::ostream& os);	//������
	void InteractionOfInfo(std::ostream& os);		//��ʾ�����Ϣ
	//�������ֵ���ƽ���...
	char getGearDrive() const { return chGearDrive; }
	char getAxle() const { return chAxle; }
	char getTotal() const { return chTotal; }
	char getDrive() const { return chDrive; }
	char getPart() const { return chPart; }			
	char getShow()const { return chShow; }
	char getBearing()const { return chBearing; }

	void setTotal(char ch) { chTotal = ch;}			
	void setDrive(char ch) { chDrive = ch; }
	void setPart(char ch) { chPart = ch; }
	void setGearDrive(char ch) { chGearDrive = ch; }
	void setKey(char ch) { chKey = ch; }
	void setShow(char ch) { chShow = ch; }
	void setBearing(char ch) { chBearing = ch; }

private:
	char chTotal;									//����ѡ��
	char chDrive;									//����ѡ��
	char chPart;									//���ѡ��
	char chGearDrive;								//���ִ���
	char chKey;										//�������
	char chAxle;									//������
	char chBearing;									//��е����
	char chShow;									//�����Ϣ
};

#endif
