#pragma once
#ifndef GEAR_DRIVE_H
#define GEAR_DRIVE_H
#define SHOW_DETAIL				//ʹ�ú�����֤��ʾÿһ���������
#include "drive_design.h"
#include "gear.h"
//��ʼ��Ƴ��ִ���
class Gear_Drive : public Drive_Design {
public:
	Gear_Drive(shared_ptr<Gear> p1 = nullptr, shared_ptr<Gear> p2 = nullptr)noexcept :
		Drive_Design(), part1(p1), part2(p2) {
	}
	virtual ~Gear_Drive() {};	//����һ���������
protected:
	shared_ptr<Gear> part1;		//�����������
	shared_ptr<Gear> part2;		
	//�غ�ϵ��K = KA*KV*Ka*Kb
	double K = 1;
	double KT = 1.3;			//����ϵ��
	double KA = 1.0;			//ʹ��ϵ��
	double KFa = 1.2;			//�ݼ��غɷ���ϵ��
	double KFb = 1.2;			//�����غɷ���ϵ��
	double KHa = 1.2;
	double KHb = 1.2;			//�Ӵ�ƣ�Ͷ�Ӧ�ĳ����غɷ���ϵ��
	//���ֵ���������
	double Ft1 = 0;				//Բ���� = 2*T1/d1
	double Fr1 = 0;				//������ Ft1*tan(a)
	double Fn1 = 0;				//���巨���� Ft1/cos(a)
	//�ݸ�����ƣ��ǿ��
	double Ye = 0;				//�غ϶�ϵ��
	double YFa = 0;				//����ϵ����ֻ��������״�й�
	double YSa = 0;				//Ӧ������ϵ��
	//����Ӵ�ƣ��ǿ��
	double ZE = 189.8;			//����Ӱ��ϵ��
	double Ze = 0;				//�Ӵ�ƣ��ǿ�ȵ��غ϶�ϵ��
	double ZH = 0;				//����ϵ��
	//ƣ�ͼ���
	double OF = 0;				//��������
	double OH = 0;				//ƣ�ͼ���
	double SF = 1.5;			//������ȫϵ��
	double SH = 1.2;			//�Ӵ���ȫϵ��
	//����ϵ��
	double KFN1 = 0.88;			//����
	double KFN2 = 0.91;			
	double KHN1 = 0;			//ƣ��
	double KHN2 = 0;
	//��������
	double v = 1;				//Բ���ٶ�
	double j = 1.0;				//����ÿתһȦʱͬһ��������ϳ���,Ĭ��Ϊ1��һ�㲻��Ҫ�Ķ�
	double N = 0;				//����Ӧ��ѭ������
	double q = 1;				//����ϵ��
	double dt = 0;				//����ֶ�Բֱ��
	double mt = 0;				//����ģ��
	double a = 100;				//���ľ�
	double e = 0;				//�غ϶�
	double u = 3.2;				//������

	virtual void Bend_Fatigue_Design();								//�����ͽӴ�ƣ��ǿ�����
	virtual void Contact_Fatigue_Design();
	
protected:
	virtual void setTrialDiameter();								//��ȡ����ֱ�������Ӵ�ǿ��,Ϊ�麯��
	virtual void setTrialModulus(double OF1,double OF2,double z1,double p = 0);  //��ȡ����ģ����������ǿ��
	virtual void setGear(double z1);								//���ó��ֵĲ���
	//virtual void setDefault() = 0;								//Ĭ�ϲ������
	void setUserChoice(std::ostream&os) override;					//���û�ѡ���Ĳ��������

	virtual void setTriE(double a, double p = 0);					//����E�����Ĵ���,Ϊ�麯��
	virtual void sete(int z1, int z2, double a, double p = 0);		//�����غ϶�,Ϊ�麯��
	virtual void setYe() { Ye = 0.25 + 0.75 / e; };					//�����غ϶�ϵ��,ҲΪ�麯��
	void setOH(double OH1, double OH2);								//���ýӴ�ƣ�ͼ���
	void setOF(double& OF1, double& OF2);							//��������ƣ�ͼ���,������
	void setFourK(bool b, double v1);								//�ĸ�K�����Ĵ���
	void setdt() { dt = dt * pow(K / KT, 1.0 / 3); }				//�����ֶ�Բֱ��
	void setKT(double val) { KT = val; }							//��������ϵ��
	void setKA(double val = 1.0) { KA = 1.0; };
	void setKHN(double val1 = 0.88, double val2 = 0.91) { KHN1 = val1, KHN2 = val2; }
	void setKFN(double val1 = 0.85, double val2 = 0.88) { KFN1 = val1, KFN2 = val2; }
	void setSF(double val = 1.4) { SF = val; }
	void setSH(double val = 1.0) { SH = val; }
	void setKHbandKFb(double val, double val2) { KHb = val, KFb = val2; }
	void setK(double val) { K = val; }								//����Kֵ
	void setu(double val) { u = val; }								//�޸Ĵ�����
	void setq(double val) { q = val; }								//�޸ĳݿ�ϵ��
	void setmt(); 													//����ģ��,��Ĭ�Ϲ���Բ�����ֵ���ܳ���
	void setKHaandKFa(double d);									//����KHa��KFa����
	void setTwoY(double& YFa1, double& YSa1,double z1);				//�Զ����ò�ֵ������YFa, YSa
	//setUserChoice�����ľ��幹��
	void setBasicParameter(std::ostream& os);						//�������������������Ĳ���
	void setLifeParameter(std::ostream& os);						//����ϵ���趨
	void setKHbParameter(std::ostream& os);							//�����غɷ���ϵ��,ƣ�Ͷ�Ӧ�Ŀ���ֱ�Ӳ��
	//ʹ�ó�������ʽ�;�̬ȫ�ֱ������Ż��ڴ�
	constexpr static double TwoY[][2] = { {2.97,1.52},{2.91,1.53},{2.85,1.54},{2.80,1.55},
		{2.76,1.56},{2.72,1.57},{2.69,1.575},{2.65,1.58},{2.62,1.59},{2.60,1.595},{2.57,1.60},
		{2.55,1.61},{2.53,1.62},{2.52,1.625},{2.45,1.65},{2.40,1.67},{2.35,1.68},{2.32,1.70},
		{2.28,1.73},{2.24,1.75},{2.22,1.77},{2.20,1.78},{2.18,1.79},{2.14,1.83},{2.12,1.865},{2.06,1.97} };

};
#endif