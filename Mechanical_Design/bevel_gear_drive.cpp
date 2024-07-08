#define _CRT_SECURE_NO_WARNINGS
#include  "bevel_gear_drive.h"

Bevel_Gear_Drive::~Bevel_Gear_Drive() {
	showDesignInfo(std::cout);
}

void Bevel_Gear_Drive::setDesign() {
	setDefault();				//Ĭ�ϲ������
	Contact_Fatigue_Design();	//�Ӵ�ƣ��ǿ�����
	Bend_Fatigue_Design();	//����ƣ��ǿ�����
	setGear(dt / mt);		//��������
}

void Bevel_Gear_Drive::showDesignInfo(ostream& os){
	os << "б��Բ�����ִ�������Ҫ��Ʋ�������:\n" << std::endl;
	if (part1)
		part1->showInfo(os);
	if (part2)
		part2->showInfo(os);
	time(&timer);
	os << "���ָ������ľ��ǣ� " << a << "mm" << std::endl;
	os << "��ǰʱ���ǣ�" << ctime(&timer) << std::endl;
}

void Bevel_Gear_Drive::setTriE(double a, double p) {
	double at = atan(tan(a) / cos(p));
	double c = Angle_To_Radian(120);
	double pb = atan(tan(p) * cos(at));
	ZH = sqrt(2 * cos(pb) / (cos(at) * sin(at)));
	Zp = sqrt(cos(p));
	Ze = sqrt((4 - ea) / 3 * (1 - ep) + ep / ea);

	double ev = ea / (cos(pb) * cos(pb)); 
	Ye = 0.25 + 0.75 / ev;		//������ֱ�����Ye
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
	val3 *= val3; //ȡƽ��
	dt = pow(val1 * val2 * val3, 1.0 / 3); //ע�Ⱑ��Ҫ1.0��ע������ת��
}

void Bevel_Gear_Drive::Contact_Fatigue_Design(){
	int z1 = part1->getZ(), z2 = part2->getZ();
	int B1 = part1->getB(), d1 = part1->getd();
	double a = Angle_To_Radian(part1->geta());
	double p = Angle_To_Radian(part1->getp());
	double OH1 = part1->getOH(), OH2 = part2->getOH();
	sete(z1, z2, a,p);				//�����غ϶�
	setTriE(a,p);						//����E�������趨
	setOH(OH1, OH2);				//��ȡ�Ӵ�ƣ�ͼ���
	setTrialDiameter();				//��ȡ����ֶ�Բֱ��
	setKHaandKFa(dt);					//����Բ���ٶ�
	setFourK(1,1.10);					//�ĸ��Ӵ�ƣ��K������ȷ��	
	setdt();						//����С���ֶַ�Բֱ��
	mt = dt / z1;					//�Ӵ�ƣ�Ͷ�Ӧ��ģ��
}

void Bevel_Gear_Drive::Bend_Fatigue_Design(){
	int z1 = part1->getZ();
	double p = Angle_To_Radian(part1->getp());
	double OF1 = part1->getOF(), OF2 = part2->getOF();
	setYe();						//�����غ϶�ϵ��
	setOF(OF1, OF2);				//��������ƣ�ͼ���
	setTrialModulus(OF1, OF2, z1,p);	//����������Ӧ��ģ��

	//��������ģ��
	double d1 = mt * z1/cos(p);	//�ֶ�Բ�뾶
	setKHaandKFa(d1);			//����Բ���ٶ�
	double h = (2 * HA + C) * mt;	//�����߱�
	h /= d1*q;
	Ft1 = 2 * T1 / d1;
	setFourK(0,1.07);					//�ĸ��Ӵ�ƣ��K������ȷ��	
	setmt();						//ģ���ĵ���
}

void Bevel_Gear_Drive::setTrialModulus(double OF1, double OF2, double z1,double p) {
	double YFa1 = 0, YFa2 = 0;	//����ϵ��
	double YSa1 = 0, YSa2 = 0;	//Ӧ������ϵ��
	double zt = z1 / pow(cos(p), 3);
	double z2 = zt * u;
	setTwoY(YFa1, YSa1, zt);		
	setTwoY(YFa2, YSa2, z2);
	double val1 = std::max(YFa1 * YSa1 / OF1, YFa2 * YSa2 / OF2);
	double val2 = 2 * KT * T1 * Ye *Yp*cos(p)*cos(p)/ (q * z1 * z1);
	mt = pow(val2 * val1, 1.0 / 3); //����ģ��
}

void Bevel_Gear_Drive::setGear(double z1) {
	double p = Angle_To_Radian(part1->getp());
	z1 *= cos(p);	
	double z2 = z1 * u;
	z2 = round(z2);		//Բ��һ��z2
	a = (z1 + z2)*mt / (2 * cos(p));
	a = round(a);	//Բ��һ��a
	int z = z1;		//����z1
	z1 = z;
	p = acos((z1 + z2) * mt / (2 * a));
	double d1 = z1 * mt/cos(p), d2 = z2 * mt/(cos(p));
	double b = q * d1;
	b = round(b);
	double b1 = b + 5;
	part1->setm(mt);			//���ģ��
	part2->setm(mt);
	part1->setZ(z1);			//���ó���
	part2->setZ(z2);
	part1->setd(d1);			//���÷ֶ�Բ�뾶
	part2->setd(d2);
	part1->setB(b1);			//���óݿ�
	part2->setB(b);
	p = p *180 / M_PI;
	part1->setp(p);
	part2->setp(p);
	part1->setRot("����");
	part2->setRot("����");
}

void Bevel_Gear_Drive::setDefault() {
	setT(P / n * 9550000);
	setu(3.2);
	setq(1);
	setSH(1.0);
	setKHN(0.88, 0.91);	//����ϵ���밲ȫϵ��
	setKFN(0.85, 0.88);	//��������ϵ��
	setSF(1.4);	//
	setKA();
	//setKHaandKFa();
	setKHbandKFb(1.318, 1.28);
}