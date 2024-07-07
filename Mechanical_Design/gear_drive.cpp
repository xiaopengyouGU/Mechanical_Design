#include "gear_drive.h"

void Gear_Drive::Contact_Fatigue_Design() {
	T1 = P / n * 9550000;
	part1->setZ(24);
	part2->setZ(77);
	int z1 = part1->getZ(), z2 = part2->getZ();
	int B1 = part1->getB(), d1 = part1->getd();
	u = 3.2; //获取传动比
	double a = Angle_To_Radian(part1->geta());
	N = 60 * n * j * Lh;
	int N2 = N / u;
	double OH1 = part1->getOH(), OH2 = part2->getOH();
	OH1 = 600, OH2 = 550;
	q = 1;			//齿宽系数
	sete(z1, z2, a);				//计算重合度
	setTriE(a);						//三个E常数的设定
	setOH(OH1, OH2);				//获取接触疲劳极限
	setTrialDiameter();				//获取试算分度圆直径
	setFourK(1);					//四个接触疲劳K常数的确定	
	setdt();						//调整小齿轮分度圆直径
	double v = M_PI *dt * n / (60 * 1000);//实际的圆周速度
	double b1 = q * dt;            //齿宽
	Ft1 = 2 * T1 /dt;
	mt = dt / z1;					//接触疲劳对应的模数
}

void Gear_Drive::Bend_Fatigue_Design() {
	int z1 = part1->getZ();
	double OF1 = part1->getOF(), OF2 = part2->getOF();
	OF1 = 500; OF2 = 320;
	setYe();						//计算重合度系数
	setOF(OF1,OF2);				//设置弯曲疲劳极限
	setTrialModulus(OF1, OF2, z1);	//计算弯曲对应的模数,这一步有问题!!!

	//调整齿轮模数
	double d1 = mt * z1;	//分度圆半径
	double v = M_PI * d1 * n / (60 * 1000);			//圆周速度
	double b1 = q * d1;			//齿宽
	double h = (2 * HA + C) * mt;	//计算宽高比
	h /= b1;
	Ft1 = 2 * T1 / d1;
	double tmp = KA * Ft1 / b1;
	setFourK(0);					//四个接触疲劳K常数的确定	
	setmt();						//模数的调整
}

void Gear_Drive::setGear(double z1) {	//计算齿宽中心距等
	double z2 = z1 * u;
	z1 = round(z1), z2 = round(z2); //圆整一下两个值
	double d1 = z1 * mt, d2 = z2 * mt;
	double b = q * d1;
	double b1 = b + 5;
	part1->setm(mt);			//设计模数
	part2->setm(mt);
	part1->setZ(z1);			//设置齿数
	part2->setZ(z2);
	part1->setd(d1);			//设置分度圆半径
	part2->setd(d2);
	part1->setB(b1);			//设置齿宽
	part2->setB(b);	
	a = (d1 + d2) / 2;
	a = round(a);
}

void Gear_Drive::sete(int z1, int z2, double a, double p) {
	double a1 = acos(z1 * cos(a) / (z1 + 2 * HA));
	double a2 = acos(z2 * cos(a) / (z2 + 2 * HA));
	e = (z1 * (tan(a1) - tan(a)) + z2 * (tan(a2) - tan(a))) / (2 * M_PI); 
}

void Gear_Drive::setTriE(double a, double p) {	//三个E常数的设计
	Ze = sqrt((4.0 - e) / 3); //重合度系数计算;
	ZH = sqrt(2 / (cos(a) * sin(a)));
	ZE = 189.8;          //弹性系数计算
}

void Gear_Drive::setOH(double OH1, double OH2) {
	SH = 1;			//设置接触疲劳安全系数
	KN1 = 0.88, KN2 = 0.91;				//设置两个接触疲劳寿命系数
	OH = std::min(KN1 * OH1 / SH, KN2 * OH2 / SH); //取最小值
}

void Gear_Drive::setOF(double& OF1, double& OF2) {
	KN1 = 0.85, KN2 = 0.88;
	SF = 1.4;
	double O1 = OF1, O2 = OF2;
	OF1 = KN1 * O1 / SF, OF2 = KN2 * O2 / SF;
}

void Gear_Drive::setTrialDiameter() {
	//获取试算接触疲劳强度对应的分度圆半径
	double val1 = 2 * KT * T1 / q;
	double val2 = (u + 1) / u;
	double val3 = (ZH * ZE * Ze / OH);
	val3 *= val3; //取平方
	dt = pow(val1*val2*val3, 1.0 / 3); //注意啊，要1.0！注意类型转换
}

void Gear_Drive::setTrialModulus(double OF1,double OF2,int z1,double p) {
	double YFa1 = 2.65, YFa2 = 2.33;	//齿形系数
	double YSa1 = 1.58, YSa2 = 1.76;	//应力修正系数
	double val1 = std::max(YFa1 * YSa1 / 304, YFa2 * YSa2 / 201);
	double val2 = 2 * KT * T1 * Ye / (q * z1 * z1);
	mt = pow(val2 * val1, 1.0 / 3); //试算模数
}

void Gear_Drive::setFourK(bool b) {
	if (b) {
		KA = 1.0;
		KHa = 1.2;
		KHb = 1.320;
		KV = 1.12;
		K = KA * KV * KHa * KHb;
	}
	else {
		KA = 1.0;
		KFb = 1.276;
		KFa = 1.0;
		KV = 1.08;
		K = KA * KV * KFa * KFb;
	}
}
