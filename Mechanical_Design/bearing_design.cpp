#define _CRT_SECURE_NO_WARNINGS
#include "bearing_design.h"

void Bearing_Design::setDesign(bool b) {
	Name = "轴承设计";
	if (b)
		setDefault();
	else
		setUserChoice(std::cout);
	setXandY();					//确定径向和轴向动载系数
	testC(std::cout);			//验算寿命
}

void Bearing_Design::showDesignInfo(std::ostream& os) {
	os << Name <<":" << std::endl;
	os << "载荷性质 ：" << Load << std::endl;
	part->showInfo(os);
	time(&timer);
	os << "设计编号：" << Num << std::endl;
	os << "当前时间：" << ctime(&timer) << std::endl;
}

void Bearing_Design::setXandY() {
	//用插值法确定两个动载系数
	double val1 = Fa*1.0 / Fr, val2 = Fa*1.0 / Co;		//这里的单位换算很重要
	if (part->gettype() == "深沟球轴承") {	//深沟球轴承
		if (val2 < 0.025) e = 0.22;
		else if (val2 < 0.040) e = 0.22;
		else if (val2 < 0.070) e = 0.24;
		else if (val2 < 0.130) e = 0.27;
		else if (val2 < 0.250) e = 0.31;
		else if (val2 < 0.500) e = 0.37;
		else e = 0.44;

		if (val1 <= e) {
			X = 1.0;
			Y = 0;
		}
		else {
			X = 0.56;
			if (e == 0.22) {
				Y = 2.0 - 0.2 / (0.040 - 0.025) * (val2 - 0.025);
			}
			else if (e == 0.24) {
				Y = 1.8 - 0.2 / (0.070 - 0.040) * (val2 - 0.040);
			}
			else if (e == 0.27) {
				Y = 1.6 - 0.2 / (0.130 - 0.070) * (val2 - 0.070);
			}
			else if (e == 0.31) {
				Y = 1.4 - 0.2 / (0.250 - 0.130) * (val2 - 0.130);
			}
			else if (e == 0.37) {
				Y = 1.2 - 0.2 / (0.50 - 0.25) * (val2 - 0.25);
			}
			else if (e == 0.44) {
				Y = 1.0 - 0.2 / (1 - 0.5) * (val2 - 0.5);
			}
		}
	}
	else if (part->gettype() == "角接触球轴承AC") { //角接触球轴承
		e = 0.68;
		if (val1 <= e) {
			X = 1.0;
			Y = 0;
		}
		else {
			X = 0.41, Y = 0.87;
		}
	}
}

void Bearing_Design::testC(ostream&os) {
	//验算额定动载荷
	P = fd * (X * Fr + Y * Fa);		//确定当量动载荷
	double tmp = P * pow(60.0 * n * Lh / 1000000, 1.0 / 3),tmpLh;
	tmpLh = 1000000 * 1.0 * pow(Cd / P, 3)/(60.0*n);
	os << "径向动载系数X = " << X << "\t" << "轴向动载系数Y = " << Y << std::endl;
	os << "当量动载荷P = " << P << "N";
	os << "基本额定动载荷是：" << Cd<< "N"<< std::endl;
	os << "预期动载荷是：" << tmp <<  "N" << std::endl;
	double tmpCo, tmpC;
	while (Cd <= tmp) {
		os << "预期寿命未能达到！" << std::endl;
		os << "寿命只有" << tmpLh << std::endl;
		os << "请输入新轴承的Co和C" << std::endl;
		std::cin >> tmpCo >> tmpC;
		setCd(tmpC);
		setCo(tmpCo);
		setXandY();					//调整X和Y值
		P = fd * (X * Fr + Y * Fa);	//确定当量动载荷
		tmp = P * pow(60.0 * n * Lh / 1000000, 1.0 / 3);
		tmpLh = 1000000 * 1.0 * pow(Cd / P,3)/(60.0*n);
	}
	os << "预期寿命是：" << tmpLh  << "h" << std::endl;
	os << std::endl;
}

void Bearing_Design::setBasicParameter(ostream& os) {
	double tmpn, tmpFr, tmpFa, tmpfd, tmpLh;
	os << "请输入轴承的转速n：" << std::endl;
	std::cin >> tmpn;
	setn(tmpn);
	os << "请输入径向载荷Fr：" << std::endl;
	std::cin >> tmpFr;
	setFr(tmpFr);
	os << "请输入轴向载荷Fa：" << std::endl;
	std::cin >> tmpFa;
	setFa(tmpFa);
	os << "请输入预期寿命Lh：" << std::endl;
	std::cin >> tmpLh;
	setLh(tmpLh);
	os << "无冲击或轻微冲击的条件下fd = 1-1.2,请选择一个数：" << std::endl;
	std::cin >> tmpfd;
	setfd(tmpfd);
}

void Bearing_Design::setBearingParameter(std::ostream& os) {
	part->setInfo(os);			//轴承设定
	double tmpC, tmpCo;
	os << "根据选定的轴承型号，请输入额定动载荷C和额定静载荷Co" << std::endl;
	std::cin >> tmpC >> tmpCo;
	setCd(tmpC);
	setCo(tmpCo);
}

void Bearing_Design::setUserChoice(ostream& os) {
	setBasicParameter(os);		//默认参数设定
	setBearingParameter(os);	//轴承参数设定
}

void Bearing_Design::setDefault() {
	//什么也不做
}

