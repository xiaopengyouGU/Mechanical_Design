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
	os << "设计编号是：" << Num << std::endl;
	os << "当前时间是：" << ctime(&timer) << std::endl;
}

Spur_Gear_Drive::~Spur_Gear_Drive() {
	showDesignInfo(std::cout);
}

void Spur_Gear_Drive::setDesign() {
	Name = "直齿圆柱齿轮传动";	//设计名称
	setDefault();
	Contact_Fatigue_Design();	//接触疲劳强度设计
	Bend_Fatigue_Design();	//弯曲疲劳强度设计
	setGear(dt / mt);		//调整齿数
}

void Spur_Gear_Drive::setDefault() {	//默认参数设计
	setT(P / n * 9550000);
	setu(3.2);
	setq(1);
	setSH(1.0);
	setKHN(0.88, 0.91);	//寿命系数与安全系数
	setKFN(0.85, 0.88);	//设置寿命系数
	setSF(1.4);	//
//	setKHaandKFa();这一步必须在算出分度圆半径后进行
	setKA();
	setKHbandKFb(1.320, 1.276);
}