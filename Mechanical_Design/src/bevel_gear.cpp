#include "bevel_gear.h"

void Bevel_Gear::showInfo(ostream& os) {
	os << "��б���ֵĲ������£�" << "\n";
	os << "����z = " << Z << "\n";
	os << "���b = " << B << "\n";
	os << "������p = " << p << "\n";
	os << "�ֶ�Բֱ��d = " << d << "\n";
	os << "ģ��m = " << m << "\n";
	os << "ѹ����a = " << a << "��" << "\n";
	os << "�����ǣ�" << Material << "\n";
	os << "Ӳ���ǣ�" << Hardness << "\n";
	os << "���ȵȼ�Level = " << Level << "\n";
}

Bevel_Gear::~Bevel_Gear() {
	showInfo(std::cout);
}