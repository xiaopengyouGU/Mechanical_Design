#include "bearing.h"

void Bearing::setInfo(ostream& os) {
	//ȷ���ھ�����
	string c;
	int val;
	os << "����ھ�һ��Ϊ5�ı���,�ھ�����Ϊ�ھ��ߴ类5���õ�����" << std::endl;
	os << "���ھ�Ϊ10,12,15,17����У���������Ϊ00,01,02,03" << std::endl;
	os << "���������ھ����������ھ����ţ�" << std::endl;
	std::cin >> val >> c;
	setd(val);
	setCode(c);
}

//��������
void Deep_Bearing::showInfo(std::ostream& os) {
	os << "�������еĲ������£�" << std::endl;
	os << "�ھ�����Ϊ��" << code << std::endl;
	os << "�ھ�Ϊ��" << d << "mm" << std::endl;
	os << std::endl;
}

//�ԽǽӴ������AC
void Angle_Bearing::showInfo(std::ostream& os) {
	os << "�ýǽӴ������AC�Ĳ������£�" << std::endl;
	os << "�ھ�����Ϊ��" << code << std::endl;
	os << "�ھ�Ϊ��" << d << "mm" << std::endl;
	os << std::endl;
}