#pragma once
#ifndef SPUR_GEAR_DRIVE_H
#define SPUR_GEAR_DRIVE_H
#include "gear_drive.h"
#include "spur_gear.h"
//ֱ��Բ�����ִ���
class Spur_Gear_Drive : public Gear_Drive {
public:
	Spur_Gear_Drive(bool b = true, shared_ptr<Spur_Gear> p1 = nullptr, shared_ptr<Spur_Gear> p2 = nullptr)
		:Gear_Drive(p1, p2) {
		setDesign(b);							//��ʼ���
	}
	
	~Spur_Gear_Drive();

	void setDefault() override;					//�����û��ֶ�����
	void setDesign(bool b) override;			//������һ�����麯��
	void showDesignInfo(ostream& os) override ; //���ش��麯��
private:
};
#endif