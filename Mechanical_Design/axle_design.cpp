#define _CRT_SECURE_NO_WARNINGS
#include "axle_design.h"

void Axle_Design::setDesign(bool b) {
	Name = "轴的设计";
	if (b)
		setDefault();
	else
		setUserChoice(std::cout);
	testt(std::cout);
}

void Axle_Design::showDesignInfo(std::ostream& os) {
	os << "轴的主要设计参数如下：" << std::endl;
	os << "载荷性质 ：" << Load << std::endl;
	part->showInfo(os);
	time(&timer);
	os << "设计编号：" << Num << std::endl;
	os << "当前时间：" << ctime(&timer) << std::endl;
}

void Axle_Design::setDefault() {
	setT(9550000.0 * P / n);
}

void Axle_Design::setUserChoice(std::ostream& os) {
	double tmpP, tmpn, tmpKA;
	os << "请输入传递的功率P(Kw): " << std::endl;
	std::cin >> tmpP;
	os << "请输入转速n(r/min): " << std::endl;
	std::cin >> tmpn;
	os << "请输入计算安全系数KA：" << std::endl;
	std::cin >> tmpKA;
	setP(tmpP);
	setn(tmpn);
	setKA(tmpKA);
	setT(KA*9550000.0 * P / n);
}

void Axle_Design::testt(std::ostream& os) {
	double d = part->getd(),t = part->gett();
	double tmp = T / (0.2 * pow(d, 3)),tmpd = 20;	//获取最大切应力
	while (tmp > t) {
		os << "当前最大切应力为：" << tmp  << "Mpa"
			<< "\t" << "最大允许切应力：" << t  << "Mpa" << std::endl;
		os << "扭转强度不够，请调整轴的直径:" << std::endl;
		std::cin >> tmpd;
		tmp = T / (0.2 * pow(tmpd, 3));
		part->setd(tmpd);
	}
	os << "扭转强度足够！" << std::endl;
}
