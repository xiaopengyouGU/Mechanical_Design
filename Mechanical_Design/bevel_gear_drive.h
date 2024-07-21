#pragma once
#ifndef BEVEL_GEAR_DRIVE_H
#define BEVEL_GEAR_DRIVE_H
#include "gear_drive.h"
#include "bevel_gear.h"

class Bevel_Gear_Drive : public Gear_Drive {
public:
	Bevel_Gear_Drive(bool b = true,shared_ptr<Bevel_Gear> p1 = nullptr, shared_ptr<Bevel_Gear> p2 = nullptr) :
		Gear_Drive(p1, p2) {
		setDesign(b);									//����Ĭ��ʵ��
	}
	~Bevel_Gear_Drive();
	void setDesign(bool b) override;					//���ظú���
	void showDesignInfo(ostream& os) override;			//���ش��麯��
	void Contact_Fatigue_Design() override;				//����
	void Bend_Fatigue_Design() override;
private:
	double Fa1 = 0;										//������
	double Yp = 1.0;									//������Ӧ��������ϵ��
	double Zp = 1.0;									//�Ӵ��Ե�������ϵ��
	double ea = 1.0;									//�������ֵ��غ϶�
	double ep = 1.0;									//�����غ϶�
	
	void setDefault() override;
	void setTrialDiameter() override;
	void setTrialModulus(double OF1, double OF2, double z1, double p) override;
	void setGear(double z1) override;

	void setTriE(double a, double p)override;			//�����麯��
	void sete(int z1, int z2, double a, double p) override;
	void setYe() override { };							//����ŵ�setTriE����
};
#endif