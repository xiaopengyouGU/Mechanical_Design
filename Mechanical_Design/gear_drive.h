#pragma once
#ifndef GEAR_DRIVE_H
#define GERA_DRIVE_H
#include "drive_design.h"
#include "gear.h"
//��ʼ��Ƴ��ִ���
class Gear_Drive : public Drive_Design {
public:
	Gear_Drive(shared_ptr<Gear> p1 = nullptr, shared_ptr<Gear> p2 = nullptr)noexcept :
		Drive_Design(), part1(p1), part2(p2) {
	}	//���γߴ����}
	virtual ~Gear_Drive() {}; //����һ���������
protected:
	shared_ptr<Gear> part1;
	shared_ptr<Gear> part2;
	double e = 0; //�غ϶�
	double u = 3.2; //������
	//�غ�ϵ��K = KA*KV*Ka*Kb
	double K = 1;
	double KT = 1.3;		//����ϵ��
	double KA = 1.0; //ʹ��ϵ��
	double KFa = 1.2; //�ݼ��غɷ���ϵ��
	double KFb = 1.2; //�����غɷ���ϵ��
	double KHa = 1.2;
	double KHb = 1.2; //�Ӵ�ƣ�Ͷ�Ӧ��
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
	double KN1 = 0.88;    //����ϵ��
	double KN2 = 0.91;		//
	int j = 1;        //����ÿתһȦʱͬһ��������ϳ���
	double N = 0;        //����Ӧ��ѭ������
	double q = 1;        //���ϵ��
	double dt = 0;
	double mt = 0;
	double a = 100; //���ľ�
	//�����ͽӴ�ƣ��ǿ�����
	virtual void Bend_Fatigue_Design();
	virtual void Contact_Fatigue_Design();

protected:
	double Angle_To_Radian(double angle) { return angle / 180 * M_PI; }; //�ǶȻ���
	virtual void sete(int z1, int z2, double a, double p = 0);					//�����غ϶�,Ϊ�麯��
	virtual void setYe() { Ye = 0.25 + 0.75 / e; };					//�����غ϶�ϵ��,ҲΪ�麯��
	void setOH(double OH1, double OH2);					//���ýӴ�ƣ�ͼ���
	void setOF(double& OF1, double& OF2);					//��������ƣ�ͼ���,������
	virtual void setTrialDiameter(); //��ȡ����ֱ�������Ӵ�ǿ��,Ϊ�麯��
	virtual void setTrialModulus(double OF1,double OF2,int z1,double p = 0);  //��ȡ����ģ����������ǿ��//��ȡ����ƣ�ͼ���
	virtual void setTriE(double a,double p = 0);  //����E�����Ĵ���,Ϊ�麯��
	virtual void setFourK(bool b);		//�ĸ�K�����Ĵ���
	void setdt() { dt = dt * pow(K / KT, 1.0 / 3); }				//�����ֶ�Բֱ��
	void setmt() {
		mt = mt * pow(K / KT, 1.0 / 3);	//ֱ��������ƣ�͵ļ������ģ��
		mt = round(mt);
	};																//����ģ��

	virtual void setGear(double z1);			//���ó��ֵĲ���

};
#endif