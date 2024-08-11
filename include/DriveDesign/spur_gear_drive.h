#pragma once
#ifndef SPUR_GEAR_DRIVE_H
#define SPUR_GEAR_DRIVE_H
#include "gear_drive.h"
#include "spur_gear.h"
//直齿圆柱齿轮传动
class Spur_Gear_Drive : public Gear_Drive {
public:
	Spur_Gear_Drive(bool b = true, shared_ptr<Spur_Gear> p1 = nullptr, shared_ptr<Spur_Gear> p2 = nullptr)
		:Gear_Drive(p1, p2) {
		setDesign(b);							//开始设计
	}
	
	~Spur_Gear_Drive();

	void setDefault() override;					//重载用户手动操作
	void setDesign(bool b) override;			//重载另一个纯虚函数
	void showDesignInfo(ostream& os) override ; //重载纯虚函数
private:
};
#endif