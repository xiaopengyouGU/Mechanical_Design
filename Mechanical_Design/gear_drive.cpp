#include "gear_drive.h"

void Gear_Drive::Contact_Fatigue_Design() {
	T1 = P / n * 9550000;
	part1->setZ(24);
	part2->setZ(77);
	int z1 = part1->getZ(), z2 = part2->getZ();
	int B1 = part1->getB(), d1 = part1->getd();
	u = 3.2; //��ȡ������
	double a = Angle_To_Radian(part1->geta());
	N = 60 * n * j * Lh;
	int N2 = N / u;
	double OH1 = part1->getOH(), OH2 = part2->getOH();
	OH1 = 600, OH2 = 550;
	q = 1;			//�ݿ�ϵ��
	sete(z1, z2, a);				//�����غ϶�
	setTriE(a);						//����E�������趨
	setOH(OH1, OH2);				//��ȡ�Ӵ�ƣ�ͼ���
	setTrialDiameter();				//��ȡ����ֶ�Բֱ��
	setFourK(1);					//�ĸ��Ӵ�ƣ��K������ȷ��	
	setdt();						//����С���ֶַ�Բֱ��
	double v = M_PI *dt * n / (60 * 1000);//ʵ�ʵ�Բ���ٶ�
	double b1 = q * dt;            //�ݿ�
	Ft1 = 2 * T1 /dt;
	mt = dt / z1;					//�Ӵ�ƣ�Ͷ�Ӧ��ģ��
}

void Gear_Drive::Bend_Fatigue_Design() {
	int z1 = part1->getZ();
	double OF1 = part1->getOF(), OF2 = part2->getOF();
	OF1 = 500; OF2 = 320;
	setYe();						//�����غ϶�ϵ��
	setOF(OF1,OF2);				//��������ƣ�ͼ���
	setTrialModulus(OF1, OF2, z1);	//����������Ӧ��ģ��,��һ��������!!!

	//��������ģ��
	double d1 = mt * z1;	//�ֶ�Բ�뾶
	double v = M_PI * d1 * n / (60 * 1000);			//Բ���ٶ�
	double b1 = q * d1;			//�ݿ�
	double h = (2 * HA + C) * mt;	//�����߱�
	h /= b1;
	Ft1 = 2 * T1 / d1;
	double tmp = KA * Ft1 / b1;
	setFourK(0);					//�ĸ��Ӵ�ƣ��K������ȷ��	
	setmt();						//ģ���ĵ���
}

void Gear_Drive::setGear(double z1) {	//����ݿ����ľ��
	double z2 = z1 * u;
	z1 = round(z1), z2 = round(z2); //Բ��һ������ֵ
	double d1 = z1 * mt, d2 = z2 * mt;
	double b = q * d1;
	double b1 = b + 5;
	part1->setm(mt);			//���ģ��
	part2->setm(mt);
	part1->setZ(z1);			//���ó���
	part2->setZ(z2);
	part1->setd(d1);			//���÷ֶ�Բ�뾶
	part2->setd(d2);
	part1->setB(b1);			//���óݿ�
	part2->setB(b);	
	a = (d1 + d2) / 2;
	a = round(a);
}

void Gear_Drive::sete(int z1, int z2, double a, double p) {
	double a1 = acos(z1 * cos(a) / (z1 + 2 * HA));
	double a2 = acos(z2 * cos(a) / (z2 + 2 * HA));
	e = (z1 * (tan(a1) - tan(a)) + z2 * (tan(a2) - tan(a))) / (2 * M_PI); 
}

void Gear_Drive::setTriE(double a, double p) {	//����E���������
	Ze = sqrt((4.0 - e) / 3); //�غ϶�ϵ������;
	ZH = sqrt(2 / (cos(a) * sin(a)));
	ZE = 189.8;          //����ϵ������
}

void Gear_Drive::setOH(double OH1, double OH2) {
	SH = 1;			//���ýӴ�ƣ�Ͱ�ȫϵ��
	KN1 = 0.88, KN2 = 0.91;				//���������Ӵ�ƣ������ϵ��
	OH = std::min(KN1 * OH1 / SH, KN2 * OH2 / SH); //ȡ��Сֵ
}

void Gear_Drive::setOF(double& OF1, double& OF2) {
	KN1 = 0.85, KN2 = 0.88;
	SF = 1.4;
	double O1 = OF1, O2 = OF2;
	OF1 = KN1 * O1 / SF, OF2 = KN2 * O2 / SF;
}

void Gear_Drive::setTrialDiameter() {
	//��ȡ����Ӵ�ƣ��ǿ�ȶ�Ӧ�ķֶ�Բ�뾶
	double val1 = 2 * KT * T1 / q;
	double val2 = (u + 1) / u;
	double val3 = (ZH * ZE * Ze / OH);
	val3 *= val3; //ȡƽ��
	dt = pow(val1*val2*val3, 1.0 / 3); //ע�Ⱑ��Ҫ1.0��ע������ת��
}

void Gear_Drive::setTrialModulus(double OF1,double OF2,int z1,double p) {
	double YFa1 = 2.65, YFa2 = 2.33;	//����ϵ��
	double YSa1 = 1.58, YSa2 = 1.76;	//Ӧ������ϵ��
	double val1 = std::max(YFa1 * YSa1 / 304, YFa2 * YSa2 / 201);
	double val2 = 2 * KT * T1 * Ye / (q * z1 * z1);
	mt = pow(val2 * val1, 1.0 / 3); //����ģ��
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
