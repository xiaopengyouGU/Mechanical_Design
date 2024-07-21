#define _CRT_SECURE_NO_WARNINGS
#include "bearing_design.h"

void Bearing_Design::setDesign(bool b) {
	Name = "������";
	if (b)
		setDefault();
	else
		setUserChoice(std::cout);
	setXandY();					//ȷ�������������ϵ��
	testC(std::cout);			//��������
}

void Bearing_Design::showDesignInfo(std::ostream& os) {
	os << Name <<":" << std::endl;
	os << "�غ����� ��" << Load << std::endl;
	part->showInfo(os);
	time(&timer);
	os << "��Ʊ�ţ�" << Num << std::endl;
	os << "��ǰʱ�䣺" << ctime(&timer) << std::endl;
}

void Bearing_Design::setXandY() {
	//�ò�ֵ��ȷ����������ϵ��
	double val1 = Fa*1.0 / Fr, val2 = Fa*1.0 / Co;		//����ĵ�λ�������Ҫ
	if (part->gettype() == "������") {	//������
		if (val2 < 0.025) e = 0.22;
		else if (val2 < 0.040) e = 0.22;
		else if (val2 < 0.070) e = 0.24;
		else if (val2 < 0.130) e = 0.27;
		else if (val2 < 0.250) e = 0.31;
		else if (val2 < 0.500) e = 0.37;
		else e = 0.44;

		if (val1 <= e) {
			X = 1.0;
			Y = 0;
		}
		else {
			X = 0.56;
			if (e == 0.22) {
				Y = 2.0 - 0.2 / (0.040 - 0.025) * (val2 - 0.025);
			}
			else if (e == 0.24) {
				Y = 1.8 - 0.2 / (0.070 - 0.040) * (val2 - 0.040);
			}
			else if (e == 0.27) {
				Y = 1.6 - 0.2 / (0.130 - 0.070) * (val2 - 0.070);
			}
			else if (e == 0.31) {
				Y = 1.4 - 0.2 / (0.250 - 0.130) * (val2 - 0.130);
			}
			else if (e == 0.37) {
				Y = 1.2 - 0.2 / (0.50 - 0.25) * (val2 - 0.25);
			}
			else if (e == 0.44) {
				Y = 1.0 - 0.2 / (1 - 0.5) * (val2 - 0.5);
			}
		}
	}
	else if (part->gettype() == "�ǽӴ������AC") { //�ǽӴ������
		e = 0.68;
		if (val1 <= e) {
			X = 1.0;
			Y = 0;
		}
		else {
			X = 0.41, Y = 0.87;
		}
	}
}

void Bearing_Design::testC(ostream&os) {
	//�������غ�
	P = fd * (X * Fr + Y * Fa);		//ȷ���������غ�
	double tmp = P * pow(60.0 * n * Lh / 1000000, 1.0 / 3),tmpLh;
	tmpLh = 1000000 * 1.0 * pow(Cd / P, 3)/(60.0*n);
	os << "������ϵ��X = " << X << "\t" << "������ϵ��Y = " << Y << std::endl;
	os << "�������غ�P = " << P << "N";
	os << "��������غ��ǣ�" << Cd<< "N"<< std::endl;
	os << "Ԥ�ڶ��غ��ǣ�" << tmp <<  "N" << std::endl;
	double tmpCo, tmpC;
	while (Cd <= tmp) {
		os << "Ԥ������δ�ܴﵽ��" << std::endl;
		os << "����ֻ��" << tmpLh << std::endl;
		os << "����������е�Co��C" << std::endl;
		std::cin >> tmpCo >> tmpC;
		setCd(tmpC);
		setCo(tmpCo);
		setXandY();					//����X��Yֵ
		P = fd * (X * Fr + Y * Fa);	//ȷ���������غ�
		tmp = P * pow(60.0 * n * Lh / 1000000, 1.0 / 3);
		tmpLh = 1000000 * 1.0 * pow(Cd / P,3)/(60.0*n);
	}
	os << "Ԥ�������ǣ�" << tmpLh  << "h" << std::endl;
	os << std::endl;
}

void Bearing_Design::setBasicParameter(ostream& os) {
	double tmpn, tmpFr, tmpFa, tmpfd, tmpLh;
	os << "��������е�ת��n��" << std::endl;
	std::cin >> tmpn;
	setn(tmpn);
	os << "�����뾶���غ�Fr��" << std::endl;
	std::cin >> tmpFr;
	setFr(tmpFr);
	os << "�����������غ�Fa��" << std::endl;
	std::cin >> tmpFa;
	setFa(tmpFa);
	os << "������Ԥ������Lh��" << std::endl;
	std::cin >> tmpLh;
	setLh(tmpLh);
	os << "�޳������΢�����������fd = 1-1.2,��ѡ��һ������" << std::endl;
	std::cin >> tmpfd;
	setfd(tmpfd);
}

void Bearing_Design::setBearingParameter(std::ostream& os) {
	part->setInfo(os);			//����趨
	double tmpC, tmpCo;
	os << "����ѡ��������ͺţ����������غ�C�Ͷ���غ�Co" << std::endl;
	std::cin >> tmpC >> tmpCo;
	setCd(tmpC);
	setCo(tmpCo);
}

void Bearing_Design::setUserChoice(ostream& os) {
	setBasicParameter(os);		//Ĭ�ϲ����趨
	setBearingParameter(os);	//��в����趨
}

void Bearing_Design::setDefault() {
	//ʲôҲ����
}

