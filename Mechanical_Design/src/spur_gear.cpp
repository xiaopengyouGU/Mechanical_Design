#include "spur_gear.h"


void Spur_Gear::showInfo(ostream& os) {
	os << "��ֱ���ֵĲ������£�" << "\n";
	os << "����z = " << Z << "\n";
	os << "���b = " << B << "\n";
	os << "�ֶ�Բֱ��d = " << d << "\n";
	os << "ģ��m = " << m << "\n";
	os << "ѹ����a = " << a << "��" << "\n";
	os << "�����ǣ�" << Material << "\n";
	os << "Ӳ���ǣ�" << Hardness << "\n";
	os << "���ȵȼ�Level = " << Level << "\n";
}

Spur_Gear::~Spur_Gear(){
	showInfo(std::cout);
}