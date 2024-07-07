#pragma once
#ifndef SPUR_GEAR_DRIVE_H
#define SPUR_GEAR_DRIVE_H
#include "gear_drive.h"
#include "spur_gear.h"
//直齿圆柱齿轮传动
class Spur_Gear_Drive : public Gear_Drive {
public:
	Spur_Gear_Drive(shared_ptr<Spur_Gear> p1 = nullptr, shared_ptr<Spur_Gear> p2 = nullptr)
		:Gear_Drive(p1, p2) {
		Contact_Fatigue_Design();	//接触疲劳强度设计
		Bend_Fatigue_Design();	//弯曲疲劳强度设计
		setGear(dt / mt);
	}			//确定新的齿轮参数}
	~Spur_Gear_Drive();
	void showDesignInfo(ostream& os) override ; //重载纯虚函数
private:
};
#endif