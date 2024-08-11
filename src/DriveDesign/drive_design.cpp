#include "drive_design.h"

void Drive_Design::setDrive(std::ostream& os) {
	//传动参数设定
	double tmpn, tmpLH, tmpP;
	os << "请输入小轮的转速(r/min): " << std::endl;
	std::cin >> tmpn;
	setn(tmpn);
	os << "请输入预计的工作时间(h): " << std::endl;
	std::cin >> tmpLH;
	setLh(tmpLH);
	os << "请输入小轮传递的功率(kw): " << std::endl;
	std::cin >> tmpP;
	setP(tmpP);
	setT(P / n * 9550000);		//确定转矩
}