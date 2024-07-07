#pragma once
#ifndef SPUR_GEAR_DRIVE_H
#define SPUR_GEAR_DRIVE_H
#include "gear_drive.h"
#include "spur_gear.h"
//ֱ��Բ�����ִ���
class Spur_Gear_Drive : public Gear_Drive {
public:
	Spur_Gear_Drive(shared_ptr<Spur_Gear> p1 = nullptr, shared_ptr<Spur_Gear> p2 = nullptr)
		:Gear_Drive(p1, p2) {
		Contact_Fatigue_Design();	//�Ӵ�ƣ��ǿ�����
		Bend_Fatigue_Design();	//����ƣ��ǿ�����
		setGear(dt / mt);
	}			//ȷ���µĳ��ֲ���}
	~Spur_Gear_Drive();
	void showDesignInfo(ostream& os) override ; //���ش��麯��
private:
};
#endif