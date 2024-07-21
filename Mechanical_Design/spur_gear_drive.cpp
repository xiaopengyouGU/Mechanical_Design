#define _CRT_SECURE_NO_WARNINGS
#include "spur_gear_drive.h"
void Spur_Gear_Drive::showDesignInfo(ostream&os) {
	os << "ֱ��Բ�����ִ�������Ҫ��Ʋ�������:\n" << std::endl;
	if (part1)
		part1->showInfo(os);
	if (part2)
		part2->showInfo(os);
	time(&timer);
	os << "���ָ������ľࣺ " << a << "mm" << std::endl;
	os << "��Ʊ�ţ�" << Num << std::endl;
	os << "��ǰʱ�䣺" << ctime(&timer) << std::endl;
}

Spur_Gear_Drive::~Spur_Gear_Drive() {
	//showDesignInfo(std::cout);
}

void Spur_Gear_Drive::setDesign(bool b) {
	Name = "ֱ��Բ�����ִ���";			//�������
	if (b)
		setDefault();
	else
		setUserChoice(std::cout);		//�û��ֶ�����
	Contact_Fatigue_Design();			//�Ӵ�ƣ��ǿ�����
	Bend_Fatigue_Design();				//����ƣ��ǿ�����
	setGear(dt / mt);					//��������
}

void Spur_Gear_Drive::setDefault() {	//Ĭ�ϲ������
	setT(P / n * 9550000);
	setu(3.2);
	setq(1);
	setSH(1.0);
	setSF(1.4);
	setKHN(0.88, 0.91);					//����ϵ���밲ȫϵ��
	setKFN(0.85, 0.88);					//��������ϵ��
	//setKHaandKFa();					//��һ������������ֶ�Բ�뾶�����
	setKA();
	setKHbandKFb(1.320, 1.276);			
}
