#include "spur_gear.h"


void Spur_Gear::showInfo(ostream& os) {
	os << "��ֱ���ֵĲ������£�" << std::endl;
	os << "����z = " << Z << std::endl;
	os << "���b = " << B << "mm" << std::endl;
	os << "�ֶ�Բֱ��d = " << d << "mm" << std::endl;
	os << "ģ��m = " << m << "mm" << std::endl;
	os << "ѹ����a = " << a << "��" << std::endl;
	os << "�����ǣ�" << Material << std::endl;
	os << "Ӳ���ǣ�" << Hardness << std::endl;
	os << "���ȵȼ�Level = " << Level << "��" << std::endl;
	os << std::endl;	//��ջ�����
}

Spur_Gear::~Spur_Gear(){

}