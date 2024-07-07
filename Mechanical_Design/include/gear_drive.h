#pragma once
#ifndef GEAR_DRIVE_H
#define GERA_DRIVE_H
#include "drive_design.h"
#include "gear.h"
//��ʼ��Ƴ��ִ���
class Gear_Drive : public Drive_Design {
public:
	Gear_Drive(shared_ptr<Part> p1 = nullptr, shared_ptr<Part> p2 = nullptr)noexcept:
		Drive_Design(p1,p2){}
	virtual ~Gear_Drive() = 0; //����һ���������
protected:
	double e = 0; //�غ϶�
	//�غ�ϵ��K = KA*KV*Ka*Kb
	double KA = 1.2; //ʹ��ϵ��
	double KFa = 1.2; //�ݼ��غɷ���ϵ��
	double KFb = 1.2; //�����غɷ���ϵ��
	double KHa = 1.2;
	double KFb = 1.2; //�Ӵ�ƣ�Ͷ�Ӧ��
	//���ֵ���������
	double Ft1 = 0; //Բ���� = 2*T1/d1
	double Fr1 = 0; //������ Ft1*tan(a)
	double Fn1 = 0; //���巨���� Ft1/cos(a)
	//�ݸ�����ƣ��ǿ��
	double Ye = 0;  //�غ϶�ϵ��
	double YFa = 0; //����ϵ����ֻ��������״�й�
	double YSa = 0; //Ӧ������ϵ��
	//����Ӵ�ƣ��ǿ��
	double ZE = 189.8; //����Ӱ��ϵ��
	double Ze = 0;     //�Ӵ�ƣ��ǿ�ȵ��غ϶�ϵ��
	double ZH = 0;		//����ϵ��
	//ƣ�ͼ���
	double OF = 0;		//��������
	double OH = 0;		//ƣ�ͼ���
	double SF = 1.5;   //������ȫϵ��
	double SH = 1.2;   //�Ӵ���ȫϵ��
	//
	double KN = 1;    //����ϵ��
	int j = 1;        //����ÿתһȦʱͬһ��������ϳ���
	int N = 0;        //����Ӧ��ѭ������
	//�����ͽӴ�ƣ��ǿ�����
	virtual void Bend_Fatigue_Design();
	virtual void Contact_Fatigue_Design();
};
#endif