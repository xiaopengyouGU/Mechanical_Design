#define _CRT_SECURE_NO_WARNINGS
#include  "bevel_gear_drive.h"

Bevel_Gear_Drive::~Bevel_Gear_Drive() {
	showDesignInfo(std::cout);
}

void Bevel_Gear_Drive::setDesign() {
	setDefault();				//默认参数设计
	Contact_Fatigue_Design();	//接触疲劳强度设计
	Bend_Fatigue_Design();	//弯曲疲劳强度设计
	setGear(dt / mt);		//调整齿数
}

void Bevel_Gear_Drive::showDesignInfo(ostream& os){
	os << "斜齿圆柱齿轮传动的主要设计参数如下:\n" << std::endl;
	if (part1)
		part1->showInfo(os);
	if (part2)
		part2->showInfo(os);
	time(&timer);
	os << "齿轮副的中心距是： " << a << "mm" << std::endl;
	os << "当前时间是：" << ctime(&timer) << std::endl;
}

void Bevel_Gear_Drive::setTriE(double a, double p) {
	double at = atan(tan(a) / cos(p));
	double c = Angle_To_Radian(120);
	double pb = atan(tan(p) * cos(at));
	ZH = sqrt(2 * cos(pb) / (cos(at) * sin(at)));
	Zp = sqrt(cos(p));
	Ze = sqrt((4 - ea) / 3 * (1 - ep) + ep / ea);

	double ev = ea / (cos(pb) * cos(pb)); 
	Ye = 0.25 + 0.75 / ev;		//在这里直接算好Ye
	Yp = 1 - ep * p / c;
}

void Bevel_Gear_Drive::sete(int z1, int z2, double a, double p) {
	double at = atan(tan(a) / cos(p));
	double a1 = acos(z1 * cos(at) / (z1 + 2 * HA*cos(p)));
	double a2 = acos(z2 * cos(at) / (z2 + 2 * HA*cos(p)));
	ea = (z1 * (tan(a1) - tan(at)) + z2 * (tan(a2) - tan(at))) / (2 * M_PI);
	ep = q * z1 * tan(p) / M_PI;
}

void Bevel_Gear_Drive::setTrialDiameter(){
	double val1 = 2 * KT * T1 / q;
	double val2 = (u + 1) / u;
	double val3 = (ZH * ZE * Ze *Zp/ OH);
	val3 *= val3; //取平方
	dt = pow(val1 * val2 * val3, 1.0 / 3); //注意啊，要1.0！注意类型转换
}

void Bevel_Gear_Drive::Contact_Fatigue_Design(){
	int z1 = part1->getZ(), z2 = part2->getZ();
	int B1 = part1->getB(), d1 = part1->getd();
	double a = Angle_To_Radian(part1->geta());
	double p = Angle_To_Radian(part1->getp());
	double OH1 = part1->getOH(), OH2 = part2->getOH();
	sete(z1, z2, a,p);				//计算重合度
	setTriE(a,p);						//三个E常数的设定
	setOH(OH1, OH2);				//获取接触疲劳极限
	setTrialDiameter();				//获取试算分度圆直径
	setKHaandKFa(dt);					//计算圆周速度
	setFourK(1,1.10);					//四个接触疲劳K常数的确定	
	setdt();						//调整小齿轮分度圆直径
	mt = dt / z1;					//接触疲劳对应的模数
}

void Bevel_Gear_Drive::Bend_Fatigue_Design(){
	int z1 = part1->getZ();
	double p = Angle_To_Radian(part1->getp());
	double OF1 = part1->getOF(), OF2 = part2->getOF();
	setYe();						//计算重合度系数
	setOF(OF1, OF2);				//设置弯曲疲劳极限
	setTrialModulus(OF1, OF2, z1,p);	//计算弯曲对应的模数

	//调整齿轮模数
	double d1 = mt * z1/cos(p);	//分度圆半径
	setKHaandKFa(d1);			//计算圆周速度
	double h = (2 * HA + C) * mt;	//计算宽高比
	h /= d1*q;
	Ft1 = 2 * T1 / d1;
	setFourK(0,1.07);					//四个接触疲劳K常数的确定	
	setmt();						//模数的调整
}

void Bevel_Gear_Drive::setTrialModulus(double OF1, double OF2, double z1,double p) {
	double YFa1 = 0, YFa2 = 0;	//齿形系数
	double YSa1 = 0, YSa2 = 0;	//应力修正系数
	double zt = z1 / pow(cos(p), 3);
	double z2 = zt * u;
	setTwoY(YFa1, YSa1, zt);		
	setTwoY(YFa2, YSa2, z2);
	double val1 = std::max(YFa1 * YSa1 / OF1, YFa2 * YSa2 / OF2);
	double val2 = 2 * KT * T1 * Ye *Yp*cos(p)*cos(p)/ (q * z1 * z1);
	mt = pow(val2 * val1, 1.0 / 3); //试算模数
}

void Bevel_Gear_Drive::setGear(double z1) {
	double p = Angle_To_Radian(part1->getp());
	z1 *= cos(p);	
	double z2 = z1 * u;
	z2 = round(z2);		//圆整一下z2
	a = (z1 + z2)*mt / (2 * cos(p));
	a = round(a);	//圆整一下a
	int z = z1;		//调整z1
	z1 = z;
	p = acos((z1 + z2) * mt / (2 * a));
	double d1 = z1 * mt/cos(p), d2 = z2 * mt/(cos(p));
	double b = q * d1;
	b = round(b);
	double b1 = b + 5;
	part1->setm(mt);			//设计模数
	part2->setm(mt);
	part1->setZ(z1);			//设置齿数
	part2->setZ(z2);
	part1->setd(d1);			//设置分度圆半径
	part2->setd(d2);
	part1->setB(b1);			//设置齿宽
	part2->setB(b);
	p = p *180 / M_PI;
	part1->setp(p);
	part2->setp(p);
	part1->setRot("右旋");
	part2->setRot("左旋");
}

void Bevel_Gear_Drive::setDefault() {
	setT(P / n * 9550000);
	setu(3.2);
	setq(1);
	setSH(1.0);
	setKHN(0.88, 0.91);	//寿命系数与安全系数
	setKFN(0.85, 0.88);	//设置寿命系数
	setSF(1.4);	//
	setKA();
	//setKHaandKFa();
	setKHbandKFb(1.318, 1.28);
}