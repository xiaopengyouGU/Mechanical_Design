#include "axle.h"

void Axle::showInfo(std::ostream& os) {
	os << "ֱ��Ϊ��" << d <<"mm" << std::endl;
	os << std::endl;
}

void Axle::setInfo(std::ostream& os) {
	double tmpd, tmpt;
	os << "���������ֱ����" << std::endl;
	std::cin >> tmpd;
	os << "��������Ŀ���ǿ��(Mpa)��" << std::endl;
	std::cin >> tmpt;
	setd(tmpd);
	sett(tmpt);
}