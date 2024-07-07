#define _CRT_SECURE_NO_WARNINGS
#include "spur_gear_drive.h"
void Spur_Gear_Drive::showDesignInfo(ostream&os) {
	os << "直齿圆柱齿轮传动的主要设计参数如下:\n" << std::endl;
	if (part1)
		part1->showInfo(os);
	if (part2)
		part2->showInfo(os);
	time(&timer);
	os << "齿轮副的中心距是： " << a << "mm" << std::endl;
	os << "当前时间是：" << ctime(&timer) << std::endl;
}

Spur_Gear_Drive::~Spur_Gear_Drive() {
	showDesignInfo(std::cout);
}