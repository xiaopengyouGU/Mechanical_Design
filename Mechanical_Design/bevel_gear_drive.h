#pragma once
#ifndef BEVEL_GEAR_DRIVE_H
#define BEVEL_GEAR_DRIVE_H
#include "gear_drive.h"
#include "bevel_gear.h"

class Bevel_Gear_Drive : public Gear_Drive {
public:
	Bevel_Gear_Drive(shared_ptr<Bevel_Gear> p1 = nullptr, shared_ptr<Bevel_Gear> p2 = nullptr) :
		Gear_Drive(p1, p2) {
		setDesign();
	}
	~Bevel_Gear_Drive();
	void setDesign() override;					//重载该函数
	void showDesignInfo(ostream& os) override; //重载纯虚函数
	
private:
	double Fa1 = 0;			//轴向力
	double Yp = 1.0;		//弯曲对应的螺旋角系数
	double Zp = 1.0;		//接触对的螺旋角系数
	double ea = 1.0;		//当量齿轮的重合度
	double ep = 1.0;		//轴向重合度
	
	void setDefault() override;
	void setTriE(double a, double p)override;			//重载虚函数
	void sete(int z1, int z2, double a, double p) override;
	void setTrialDiameter() override;
	void setTrialModulus(double OF1, double OF2, double z1,double p) override;
	void Contact_Fatigue_Design() override;		//重载
	void Bend_Fatigue_Design() override;
	void setYe() override { };			//计算放到setTriE中了
	void setGear(double z1) override;
};
#endif // !BEVEL_GEAR_DRIVE_H
