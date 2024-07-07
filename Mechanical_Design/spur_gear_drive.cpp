#define _CRT_SECURE_NO_WARNINGS
#include "spur_gear_drive.h"
void Spur_Gear_Drive::showDesignInfo(ostream&os) {
	os << "ֱ��Բ�����ִ�������Ҫ��Ʋ�������:\n" << std::endl;
	if (part1)
		part1->showInfo(os);
	if (part2)
		part2->showInfo(os);
	time(&timer);
	os << "���ָ������ľ��ǣ� " << a << "mm" << std::endl;
	os << "��ǰʱ���ǣ�" << ctime(&timer) << std::endl;
}

Spur_Gear_Drive::~Spur_Gear_Drive() {
	showDesignInfo(std::cout);
}