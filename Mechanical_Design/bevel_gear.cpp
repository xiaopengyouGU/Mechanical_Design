#include "bevel_gear.h"

void Bevel_Gear::showInfo(ostream& os) {
	os << "��б���ֵĲ������£�" << std::endl;
	os << "����z = " << Z << std::endl;
	os << "���b = " << B <<   "mm" << std::endl;
	os << "������p = " << p << "��" << std::endl;
	os << "�����ǣ�" << Rot << std::endl;
	os << "�ֶ�Բֱ��d = " << d <<  "mm" << std::endl;
	os << "ģ��m = " << m << "mm" << std::endl;
	os << "ѹ����a = " << a << "��" << std::endl;
	os << "�����ǣ�" << Material << std::endl;
	os << "Ӳ���ǣ�" << Hardness << std::endl;
	os << "���ȵȼ�Level = " << Level << "��" << std::endl;
	os << std::endl;	//��ջ�����
}

Bevel_Gear::~Bevel_Gear() {}