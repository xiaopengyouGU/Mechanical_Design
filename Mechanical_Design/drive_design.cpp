#include "drive_design.h"

void Drive_Design::setDrive(std::ostream& os) {
	//���������趨
	double tmpn, tmpLH, tmpP;
	os << "������С�ֵ�ת��(r/min): " << std::endl;
	std::cin >> tmpn;
	setn(tmpn);
	os << "������Ԥ�ƵĹ���ʱ��(h): " << std::endl;
	std::cin >> tmpLH;
	setLh(tmpLH);
	os << "������С�ִ��ݵĹ���(kw): " << std::endl;
	std::cin >> tmpP;
	setP(tmpP);
	setT(P / n * 9550000);		//ȷ��ת��
}