#include "part.h"
//����ʽ����

void Part::showInfo(ostream& os) {
	os << "������" << std::endl;
	os << "����Ĳ����ǣ�" << getMaterial() << std::endl;
}