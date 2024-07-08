#include "iteraction.h"

void Iteraction::setIni(std::ostream&os) {
	os << "************************************************" << std::endl;
	os << "程序名称： Mechaniacl_Design" << std::endl;
	os << "作者： Lvtou" << std::endl;
	os << "2024/7/16  CSU" << std::endl;
	os << "请选择要进行的设计:" << std::endl;
	os << "A 传动设计      B：齿轮设计            Q: 退出" << std::endl;
	std::cin >> ch1;
	if (ch1 == 'Q') {
		return;
	}
	else if (ch1 == 'A') {

	}
	else if (ch1 == 'B') {

	}
	else {
		os << "请输入正确的选项" << std::endl;
	}
}