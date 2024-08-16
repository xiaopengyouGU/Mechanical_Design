#define _CRT_SECURE_NO_WARNINGS
#include "key_design.h"

void Key_Design::setDesign(bool b) {
	Name = "平键设计";
	part = std::make_shared<Key>();		//分配内存，创建零件对象
	if (b)
		setDefault();					//默认参数设计
	else
		setUserChoice(std::cout);		//用户参与设计
	testStrength(std::cout);			//校核强度
}

void Key_Design::setUserChoice(ostream& os) {	//确定键的信息
	double tmpd, tmpb, tmpT, tmpbs, tmpL;
	string str;
	os << "请输入轴的直径：" << std::endl;
	std::cin >> tmpd;
	setd(tmpd);
	os << "请输入轮毂的宽度：" << std::endl;
	std::cin >> tmpb;
	setb(tmpb);
	os << "请输入需传递的转矩：" << std::endl;
	std::cin >> tmpT;
	setT(tmpT);
	os << "请输入载荷的性质(静载荷，轻微冲击，冲击): " << std::endl;
	std::cin >> str;							//直接输入Load也行
	setLoad(str);								
	os << "三种载荷对应的许用挤压应力分别为：" << std::endl;
	os << "静载荷 120-150	\t轻微冲击100-120	\t冲击60-90" << std::endl;
	os << "请输入对应的许用挤压应力：" << std::endl;
	std::cin >> tmpbs;
	setbs(tmpbs);
	setKeybandh(os);							//确定键长和键宽
	showPossibleL(os);							//输出键的长度系列
	os << "请输入键的长度L: " << std::endl;
	std::cin >> tmpL;
	part->setL(tmpL);
}

void Key_Design::setDefault() {
	//啥都不做
}

void Key_Design::testStrength(std::ostream& os) {	//强度校核
	double h = part->geth(), l = part->getl(), b = part->getb();
	double tmpbs = 4000.0 * T / (h * l * d), tmp;
	while (tmpbs > bs) {
		os << "当前挤压应力为：" << tmpbs << "Mpa" << std::endl;
		os << "连接的挤压强度不够，键会被压溃！" << std::endl;
		os << "请调整键的长度L，原始值:" << part->getL() << std::endl;
		showPossibleL(os);							//显示键的长度序列
		std::cin >> tmp;
		part->setL(tmp);
		l = tmp - b;						//键的有效长度
		tmpbs = 4000.0 * T / (h * l * d)/tmp;
	}
	os << "键的强度足够!" << std::endl;
}

void Key_Design::showPossibleL(std::ostream& os) {
	os << "键的长度系列L: " << std::endl;
	os << "6, 8, 10, 12, 14, 16, 18, 20, 22, 25, 28, 32, 36" << std::endl;
	os << "40, 45, 50, 56, 63, 70, 80, 90, 100, 110, 125, 140" << std::endl;
	os << "160, 180, 200, 250, 280, 320, 360, ..." << std::endl;
}

void Key_Design::showDesignInfo(std::ostream & os) {
	os << "平键的主要设计参数如下：" << std::endl;
	os << "载荷性质 ：" << Load << std::endl;
	part->showInfo(os);
	time(&timer);
	os << "设计编号：" << Num << std::endl;
	os << "当前时间：" << ctime(&timer) << std::endl;
}

void Key_Design::setKeybandh(std::ostream&os) {	//确定键的最终参数
	double b = 8, h = 7;
	if (d <= 8) {
		b = 2, h = 2;
		os << "键的长度范围：6-20" << std::endl;
	}
	else if (d <= 10) {
		b = 3, h = 3;
		os << "键的长度范围：6-36" << std::endl;
	}
	else if (d <= 12) {
		b = 4, h = 4;
		os << "键的长度范围：8-45" << std::endl;
	}
	else if (d <= 17) {
		b = 5, h = 5;
		os << "键的长度范围：10-56" << std::endl;
	}
	else if (d <= 22) {
		b = 6, h = 6;
		os << "键的长度范围：14-70" << std::endl;
	}
	else if (d <= 30) {
		b = 8, h = 7;
		os << "键的长度范围：18-90" << std::endl;
	}
	else if (d <= 38) {
		b = 10, h = 8;
		os << "键的长度范围：22-110" << std::endl;
	}
	else if (d <= 44) {
		b = 12, h = 8;
		os << "键的长度范围：28-140" << std::endl;
	}
	else if (d <= 50) {
		b = 14, h = 9;
		os << "键的长度范围：36-160" << std::endl;
	}
	else if (d <= 58) {
		b = 16, h = 10;
		os << "键的长度范围：45-180" << std::endl;
	}
	else if (d <= 65) {
		b = 18, h = 11;
		os << "键的长度范围：50-200" << std::endl;
	}
	else if (d <= 75) {
		b = 20, h = 12;
		os << "键的长度范围：56-220" << std::endl;
	}
	else if (d <= 85) {
		b = 22, h = 14;
		os << "键的长度范围：63-250" << std::endl;
	}
	else if (d <= 95) {
		b = 25, h = 14;
		os << "键的长度范围：70-280" << std::endl;
	}
	else if (d <= 110) {
		b = 28, h = 16;
		os << "键的长度范围：80-320" << std::endl;
	}
	else if (d <= 130) {
		b = 32, h = 18;
		os << "键的长度范围：90-360" << std::endl;
	}
	part->setb(b), part->seth(h);				//键宽和键高确定
}
