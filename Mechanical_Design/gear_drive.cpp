#include "gear_drive.h"

void Gear_Drive::Contact_Fatigue_Design() {
	int z1 = part1->getZ(), z2 = part2->getZ();
	int B1 = part1->getB(), d1 = part1->getd();
	double a = Angle_To_Radian(part1->geta());
	double OH1 = part1->getOH(), OH2 = part2->getOH();
	sete(z1, z2, a);				//�����غ϶�
	setTriE(a);						//����E�������趨
	setOH(OH1, OH2);				//��ȡ�Ӵ�ƣ�ͼ���
	setTrialDiameter();				//��ȡ����ֶ�Բֱ��
	setKHaandKFa(dt);				//����Բ���ٶ�
	setFourK(1,1.12);					//�ĸ��Ӵ�ƣ��K������ȷ��	
	setdt();						//����С���ֶַ�Բֱ��
	mt = dt / z1;					//�Ӵ�ƣ�Ͷ�Ӧ��ģ��
}

void Gear_Drive::Bend_Fatigue_Design() {
	int z1 = part1->getZ();
	double OF1 = part1->getOF(), OF2 = part2->getOF();
	setYe();						//�����غ϶�ϵ��
	setOF(OF1,OF2);				//��������ƣ�ͼ���
	setTrialModulus(OF1, OF2, z1);	//����������Ӧ��ģ��,��һ��������!!!

	//��������ģ��
	double d1 = mt * z1;	//�ֶ�Բ�뾶
	setKHaandKFa(d1);		//����Բ���ٶ�
	double h = (2 * HA + C) * mt;	//�����߱�
	h /= q*d1;
	setFourK(0,1.08);					//�ĸ��Ӵ�ƣ��K������ȷ��	
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
	OH = std::min(KHN1 * OH1 / SH, KHN2 * OH2 / SH); //ȡ��Сֵ
}

void Gear_Drive::setOF(double& OF1, double& OF2) {
	double O1 = OF1, O2 = OF2;
	OF1 = KFN1 * O1 / SF, OF2 = KFN2 * O2 / SF;
}

void Gear_Drive::setTrialDiameter() {
	//��ȡ����Ӵ�ƣ��ǿ�ȶ�Ӧ�ķֶ�Բ�뾶
	double val1 = 2 * KT * T1 / q;
	double val2 = (u + 1) / u;
	double val3 = (ZH * ZE * Ze / OH);
	val3 *= val3; //ȡƽ��
	dt = pow(val1*val2*val3, 1.0 / 3); //ע�Ⱑ��Ҫ1.0��ע������ת��
}

void Gear_Drive::setTrialModulus(double OF1,double OF2,double z1,double p) {
	double YFa1 = 0, YFa2 = 0;	//����ϵ��
	double YSa1 = 0, YSa2 = 0;	//Ӧ������ϵ��
	double z2 = z1 * u;
	setTwoY(YFa1, YSa1, z1);
	setTwoY(YFa2, YSa2, z2);			
	double val1 = std::max(YFa1 * YSa1 / OF1, YFa2 * YSa2 / OF2);
	double val2 = 2 * KT * T1 * Ye / (q * z1 * z1);
	mt = pow(val2 * val1, 1.0 / 3); //����ģ��
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
		std::cout << "��������" << std::endl;
		return;
	}
	else if (z1 < 30) {
		int tmp1 = z1 - 17, tmp2 = z1 + 1 - 17;
		double val1 = TwoY[tmp1][0], val2 = TwoY[tmp2][0];	//��ӦYFa
		double val3 = TwoY[tmp1][1], val4 = TwoY[tmp2][1]; //��ӦYSa
		double diff1 = val2 - val1, diff2 = val4 - val3;
		YFa1 = val1 + diff1 * (z1 - 17 - tmp1); //��ֵ��
		YSa1 = val3 + diff2 * (z1 - 17 - tmp1);
	}
	else if (z1 < 50) {
		int tmp1 = z1 - 30;
		tmp1 /= 5;
		int base = 30 - 17; //����
		int t1 = tmp1 + base, t2 = t1 + 1;
		double val1 = TwoY[t1][0], val2 = TwoY[t2][0];	//��ӦYFa
		double val3 = TwoY[t1][1], val4 = TwoY[t2][1]; //��ӦYSa
		double diff1 = val2 - val1, diff2 = val4 - val3;
		diff1 /= 5, diff2 /= 5;
		YFa1 = val1 + diff1 * (z1 - 30 - tmp1 * 5); //��ֵ��
		YSa1 = val3 + diff2 * (z1 - 30 - tmp1 * 5);
	}
	else if (z1 <= 100) {
		int tmp1 = z1 - 50;
		tmp1 /= 10;
		int base = 30 - 17 + 4; //����
		int t1 = tmp1 + base, t2 = t1 + 1;
		double val1 = TwoY[t1][0], val2 = TwoY[t2][0];	//��ӦYFa
		double val3 = TwoY[t1][1], val4 = TwoY[t2][1]; //��ӦYSa
		double diff1 = val2 - val1, diff2 = val4 - val3;
		diff1 /= 10, diff2 /= 10;
		YFa1 = val1 + diff1 * (z1 - 50 - tmp1 * 10); //��ֵ��
		YSa1 = val3 + diff2 * (z1 - 50 - tmp1 * 10);
	}
	else if (z1 < 150) {
		int base = 30 - 17 + 4 + 5;
		int t1 = base, t2 = t1 + 1;
		double val1 = TwoY[t1][0], val2 = TwoY[t2][0];	//��ӦYFa
		double val3 = TwoY[t1][1], val4 = TwoY[t2][1]; //��ӦYSa
		double diff1 = val2 - val1, diff2 = val4 - val3;
		diff1 /= 50, diff2 /= 50;
		YFa1 = val1 + diff1 * (z1 - 100); //��ֵ��
		YSa1 = val3 + diff2 * (z1 - 100);
	}
	else if (z1 <= 200) {
		int base = 30 - 17 + 4 + 5 + 1;
		int t1 = base, t2 = t1 + 1;
		double val1 = TwoY[t1][0], val2 = TwoY[t2][0];	//��ӦYFa
		double val3 = TwoY[t1][1], val4 = TwoY[t2][1]; //��ӦYSa
		double diff1 = val2 - val1, diff2 = val4 - val3;
		diff1 /= 50, diff2 /= 50;
		YFa1 = val1 + diff1 * (z1 - 150); //��ֵ��
		YSa1 = val3 + diff2 * (z1 - 150);
	}
	else {
		YFa1 = 2.06, YSa1 = 1.97;
	}

	//std::cout << "����ϵ��YFa = " << YFa1 << " " \
		<< "Ӧ������ϵ��YSa = " << YSa1 << std::endl;
}

void Gear_Drive::setKHaandKFa(double d) { //Ĭ�϶�Ӳ����ĳ��ֽ������
	int Level = std::max(part1->getLevel(), part2->getLevel());	//ѡȡ�;��ȵ�
	double v = M_PI * d * n / (60 * 1000);//ʵ�ʵ�Բ���ٶ�
	double b1 = q * d;            //�ݿ�
	Ft1 = 2 * T1 / d;
	double thre = KA * Ft1 / b1;	//��ֵ
	if (part1->getp() > 0) {	//��б����
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