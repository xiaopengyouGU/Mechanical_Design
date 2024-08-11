#include "bearing.h"

void Bearing::setInfo(ostream& os) {
	//确定内径代号
	string c;
	int val;
	os << "轴承内径一般为5的倍数,内径代号为内径尺寸被5除得的商数" << std::endl;
	os << "对内径为10,12,15,17的轴承，代号依次为00,01,02,03" << std::endl;
	os << "请先输入内径，再输入内径代号：" << std::endl;
	std::cin >> val >> c;
	setd(val);
	setCode(c);
}

//对深沟球轴承
void Deep_Bearing::showInfo(std::ostream& os) {
	os << "该深沟球轴承的参数如下：" << std::endl;
	os << "内径代号为：" << code << std::endl;
	os << "内径为：" << d << "mm" << std::endl;
	os << std::endl;
}

//对角接触球轴承AC
void Angle_Bearing::showInfo(std::ostream& os) {
	os << "该角接触球轴承AC的参数如下：" << std::endl;
	os << "内径代号为：" << code << std::endl;
	os << "内径为：" << d << "mm" << std::endl;
	os << std::endl;
}