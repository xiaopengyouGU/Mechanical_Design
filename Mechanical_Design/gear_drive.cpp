#include "gear_drive.h"

void Gear_Drive::Contact_Fatigue_Design() {
	int z1 = part1->getZ(), z2 = part2->getZ();
	int B1 = part1->getB(), d1 = part1->getd();
	double a = Angle_To_Radian(part1->geta());
	double OH1 = part1->getOH(), OH2 = part2->getOH();
	sete(z1, z2, a);				//计算重合度
	setTriE(a);						//三个E常数的设定
	setOH(OH1, OH2);				//获取接触疲劳极限
	setTrialDiameter();				//获取试算分度圆直径
	setKHaandKFa(dt);				//计算圆周速度
	setFourK(1,1.12);					//四个接触疲劳K常数的确定	
	setdt();						//调整小齿轮分度圆直径
	mt = dt / z1;					//接触疲劳对应的模数
}

void Gear_Drive::Bend_Fatigue_Design() {
	int z1 = part1->getZ();
	double OF1 = part1->getOF(), OF2 = part2->getOF();
	setYe();						//计算重合度系数
	setOF(OF1,OF2);				//设置弯曲疲劳极限
	setTrialModulus(OF1, OF2, z1);	//计算弯曲对应的模数,这一步有问题!!!

	//调整齿轮模数
	double d1 = mt * z1;	//分度圆半径
	setKHaandKFa(d1);		//计算圆周速度
	double h = (2 * HA + C) * mt;	//计算宽高比
	h /= q*d1;
	setFourK(0,1.08);					//四个接触疲劳K常数的确定	
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
	OH = std::min(KHN1 * OH1 / SH, KHN2 * OH2 / SH); //取最小值
}

void Gear_Drive::setOF(double& OF1, double& OF2) {
	double O1 = OF1, O2 = OF2;
	OF1 = KFN1 * O1 / SF, OF2 = KFN2 * O2 / SF;
}

void Gear_Drive::setTrialDiameter() {
	//获取试算接触疲劳强度对应的分度圆半径
	double val1 = 2 * KT * T1 / q;
	double val2 = (u + 1) / u;
	double val3 = (ZH * ZE * Ze / OH);
	val3 *= val3; //取平方
	dt = pow(val1*val2*val3, 1.0 / 3); //注意啊，要1.0！注意类型转换
}

void Gear_Drive::setTrialModulus(double OF1,double OF2,double z1,double p) {
	double YFa1 = 0, YFa2 = 0;	//齿形系数
	double YSa1 = 0, YSa2 = 0;	//应力修正系数
	double z2 = z1 * u;
	setTwoY(YFa1, YSa1, z1);
	setTwoY(YFa2, YSa2, z2);			
	double val1 = std::max(YFa1 * YSa1 / OF1, YFa2 * YSa2 / OF2);
	double val2 = 2 * KT * T1 * Ye / (q * z1 * z1);
	mt = pow(val2 * val1, 1.0 / 3); //试算模数
}

void Gear_Drive::setFourK(bool b,double v1) {
	setKV(v1);
	if (b) {
		setK(KA * KV * KHa * KHb);
	}
	else {
		setK(KA * KV * KFa * KFb);
	}
}

void Gear_Drive::setTwoY(double& YFa1, double& YSa1, double z1) {
	if (z1 < 17) {
		std::cout << "齿数不对" << std::endl;
		return;
	}
	else if (z1 < 30) {
		int tmp1 = z1 - 17, tmp2 = z1 + 1 - 17;
		double val1 = TwoY[tmp1][0], val2 = TwoY[tmp2][0];	//对应YFa
		double val3 = TwoY[tmp1][1], val4 = TwoY[tmp2][1]; //对应YSa
		double diff1 = val2 - val1, diff2 = val4 - val3;
		YFa1 = val1 + diff1 * (z1 - 17 - tmp1); //插值法
		YSa1 = val3 + diff2 * (z1 - 17 - tmp1);
	}
	else if (z1 < 50) {
		int tmp1 = z1 - 30;
		tmp1 /= 5;
		int base = 30 - 17; //基数
		int t1 = tmp1 + base, t2 = t1 + 1;
		double val1 = TwoY[t1][0], val2 = TwoY[t2][0];	//对应YFa
		double val3 = TwoY[t1][1], val4 = TwoY[t2][1]; //对应YSa
		double diff1 = val2 - val1, diff2 = val4 - val3;
		diff1 /= 5, diff2 /= 5;
		YFa1 = val1 + diff1 * (z1 - 30 - tmp1 * 5); //插值法
		YSa1 = val3 + diff2 * (z1 - 30 - tmp1 * 5);
	}
	else if (z1 <= 100) {
		int tmp1 = z1 - 50;
		tmp1 /= 10;
		int base = 30 - 17 + 4; //基数
		int t1 = tmp1 + base, t2 = t1 + 1;
		double val1 = TwoY[t1][0], val2 = TwoY[t2][0];	//对应YFa
		double val3 = TwoY[t1][1], val4 = TwoY[t2][1]; //对应YSa
		double diff1 = val2 - val1, diff2 = val4 - val3;
		diff1 /= 10, diff2 /= 10;
		YFa1 = val1 + diff1 * (z1 - 50 - tmp1 * 10); //插值法
		YSa1 = val3 + diff2 * (z1 - 50 - tmp1 * 10);
	}
	else if (z1 < 150) {
		int base = 30 - 17 + 4 + 5;
		int t1 = base, t2 = t1 + 1;
		double val1 = TwoY[t1][0], val2 = TwoY[t2][0];	//对应YFa
		double val3 = TwoY[t1][1], val4 = TwoY[t2][1]; //对应YSa
		double diff1 = val2 - val1, diff2 = val4 - val3;
		diff1 /= 50, diff2 /= 50;
		YFa1 = val1 + diff1 * (z1 - 100); //插值法
		YSa1 = val3 + diff2 * (z1 - 100);
	}
	else if (z1 <= 200) {
		int base = 30 - 17 + 4 + 5 + 1;
		int t1 = base, t2 = t1 + 1;
		double val1 = TwoY[t1][0], val2 = TwoY[t2][0];	//对应YFa
		double val3 = TwoY[t1][1], val4 = TwoY[t2][1]; //对应YSa
		double diff1 = val2 - val1, diff2 = val4 - val3;
		diff1 /= 50, diff2 /= 50;
		YFa1 = val1 + diff1 * (z1 - 150); //插值法
		YSa1 = val3 + diff2 * (z1 - 150);
	}
	else {
		YFa1 = 2.06, YSa1 = 1.97;
	}

	//std::cout << "齿形系数YFa = " << YFa1 << " " \
		<< "应力修正系数YSa = " << YSa1 << std::endl;
}

void Gear_Drive::setKHaandKFa(double d) { //默认对硬齿面的齿轮进行设计
	int Level = std::max(part1->getLevel(), part2->getLevel());	//选取低精度的
	double v = M_PI * d * n / (60 * 1000);//实际的圆周速度
	double b1 = q * d;            //齿宽
	Ft1 = 2 * T1 / d;
	double thre = KA * Ft1 / b1;	//阈值
	if (part1->getp() > 0) {	//对斜齿轮
		if (thre >= 100) {
			switch (Level) {
			case 7:
				KHa = KFa = 1.2;
				break;
			case 8:
				KHa = KFa = 1.4;
				break;
			case 6:
				KHa = KFa = 1.1;
				break;
			case 5:
				KHa = KFa = 1.0;
				break;
			}
		}
		else KHa = KFa= 1.4;
	}
	else {
		if (thre >= 100) {
			switch (Level) {
			case 7:
				KHa = KFa = 1.1;
				break;
			case 8:
				KHa = KFa = 1.2;
				break;
			case 6:
				KHa = KFa = 1.0;
				break;
			case 5:
				KHa = KFa = 1.0;
				break;
			}
		}
		else KHa = KFa = 1.2;
	}

}