#include "axle.h"

void Axle::showInfo(std::ostream& os) {
	os << "直径为：" << d <<"mm" << std::endl;
	os << std::endl;
}

void Axle::setInfo(std::ostream& os) {
	double tmpd, tmpt;
	os << "请输入轴的直径：" << std::endl;
	std::cin >> tmpd;
	os << "请输入轴的抗剪强度(Mpa)：" << std::endl;
	std::cin >> tmpt;
	setd(tmpd);
	sett(tmpt);
}