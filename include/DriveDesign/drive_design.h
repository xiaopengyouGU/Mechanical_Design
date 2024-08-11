#pragma once
#ifndef DRIVE_DESIGN_H
#define DRIVE_DESIGN_H
#include "design.h"

class Drive_Design : public Design {			//�������
public:
	Drive_Design(){}
	virtual ~Drive_Design() {};					//��һ���������
protected:
	int n = 970;								//С�ֵ�ת��
	int Lh = 60000;								//Ԥ�ƹ�����ʱ��
	double KV = 1.0;							//����ϵ��
	double T1 = 10000;							//С�ִ��ݵ�ת��N mm
	double P = 11;								//���빦��kw
protected:
	void setP(double val) { P = val; }			//�޸Ĺ���
	void setn(double val) { n = val; }			//�޸�С��ת��
	void setT(double val) { T1 = val; }			//�޸�ת��
	void setKV(double val) { KV = val; }		//����ϵ��
	void setLh(double val) { Lh = val; }		//����ʱ��

	void setDrive(ostream& os);					//������������
};

#endif