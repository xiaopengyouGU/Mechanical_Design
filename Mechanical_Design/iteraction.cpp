#include "iteraction.h"

void Iteraction::setIni(std::ostream&os) {
	os << "************************************************" << std::endl;
	os << "�������ƣ� Mechaniacl_Design" << std::endl;
	os << "���ߣ� Lvtou" << std::endl;
	os << "2024/7/16  CSU" << std::endl;
	os << "��ѡ��Ҫ���е����:" << std::endl;
	os << "A �������      B���������            Q: �˳�" << std::endl;
	std::cin >> ch1;
	if (ch1 == 'Q') {
		return;
	}
	else if (ch1 == 'A') {

	}
	else if (ch1 == 'B') {

	}
	else {
		os << "��������ȷ��ѡ��" << std::endl;
	}
}