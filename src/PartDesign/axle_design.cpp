#define _CRT_SECURE_NO_WARNINGS
#include "axle_design.h"

void Axle_Design::setDesign(bool b) {
	Name = "������";
	if (b)
		setDefault();
	else
		setUserChoice(std::cout);
	testt(std::cout);
}

void Axle_Design::showDesignInfo(std::ostream& os) {
	os << "�����Ҫ��Ʋ������£�" << std::endl;
	os << "�غ����� ��" << Load << std::endl;
	part->showInfo(os);
	time(&timer);
	os << "��Ʊ�ţ�" << Num << std::endl;
	os << "��ǰʱ�䣺" << ctime(&timer) << std::endl;
}

void Axle_Design::setDefault() {
	setT(9550000.0 * P / n);
}

void Axle_Design::setUserChoice(std::ostream& os) {
	double tmpP, tmpn, tmpKA;
	os << "�����봫�ݵĹ���P(Kw): " << std::endl;
	std::cin >> tmpP;
	os << "������ת��n(r/min): " << std::endl;
	std::cin >> tmpn;
	os << "��������㰲ȫϵ��KA��" << std::endl;
	std::cin >> tmpKA;
	setP(tmpP);
	setn(tmpn);
	setKA(tmpKA);
	setT(KA*9550000.0 * P / n);
}

void Axle_Design::testt(std::ostream& os) {
	double d = part->getd(),t = part->gett();
	double tmp = T / (0.2 * pow(d, 3)),tmpd = 20;	//��ȡ�����Ӧ��
	while (tmp > t) {
		os << "��ǰ�����Ӧ��Ϊ��" << tmp  << "Mpa"
			<< "\t" << "���������Ӧ����" << t  << "Mpa" << std::endl;
		os << "Ťתǿ�Ȳ�������������ֱ��:" << std::endl;
		std::cin >> tmpd;
		tmp = T / (0.2 * pow(tmpd, 3));
		part->setd(tmpd);
	}
	os << "Ťתǿ���㹻��" << std::endl;
}
