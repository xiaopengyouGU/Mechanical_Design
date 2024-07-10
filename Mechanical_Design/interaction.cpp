#include "interaction.h"

void Interaction::setIni(std::ostream&os) {	//初始化界面设置
	os << "************************************************" << std::endl;
	os << "程序名称： Mechaniacl_Design" << std::endl;
	os << "作者： Lvtou" << std::endl;
	os << "2024/7/16  CSU" << std::endl;
	os << "开始设计：" << std::endl;
	os << "可进行的设计:" << std::endl;
	os << "A 传动设计       B 零件设计" << std::endl;
	os << "************************************************\n" << std::endl;
}

void Interaction::InterationOfTotal(std::ostream& os) {
	os << "请选择您要进行的设计:" << std::endl;
	os << "A 传动设计		B 零件设计			Q 退出" << std::endl;
	std::cin >> chTotal;
	while (chTotal != 'A' && chTotal != 'B' && chTotal != 'Q') {
		os << "请输入正确的选项：" << std::endl;
		os << "A 传动设计		B 零件设计			Q 退出" << std::endl;
		std::cin >> chTotal;
	}
	os << std::endl;
}

void Interaction::InterationOfDriveDesign(std::ostream& os) {
	os << "可供选择的传动设计如下：" << std::endl;
	os << "A 直齿轮传动设计				B 斜齿轮传动设计" << std::endl;
	os << "C 带传动设计					D 链传动设计" << std::endl;
	os << "Q 退出传动设计" << std::endl;
	std::cin >> chDrive;
	char tmp[5] = { 'A', 'B','C','D','Q' };
	bool flag = true;
	for (int i = 0; i < sizeof(tmp); i++) {
		if (chDrive == tmp[i]);
		flag = false;
		break;
	}
	while (flag) {
		os << "请输入正确的选项：" << std::endl;
		os << "A 直齿轮传动设计				B 斜齿轮传动设计" << std::endl;
		os << "C 带传动设计					D 链传动设计" << std::endl;
		os << "Q 退出传动设计" << std::endl;
		std::cin >> chDrive;
		for (int i = 0; i < sizeof(tmp); i++) {
			if (chDrive == tmp[i]);
			flag = false;
			break;
		}
	}
	os << std::endl;
}

void Interaction::InterationOfPartDesign(std::ostream& os) {
	os << "可供选择的零件设计如下：" << std::endl;
	os << "A 键的设计				B 轴的设计" << std::endl;
	os << "Q 退出零件设计" << std::endl;
	std::cin >> chPart;
	char tmp[3] = { 'A', 'B','Q' };
	bool flag = true;
	for (int i = 0; i < sizeof(tmp); i++) {
		if (chDrive == tmp[i]);
		flag = false;
		break;
	}
	while (flag) {
		os << "请输入正确的选项：" << std::endl;
		os << "A 键的设计				B 轴的设计" << std::endl;
		os << "Q 退出传动设计" << std::endl;
		std::cin >> chPart;
		for (int i = 0; i < sizeof(tmp); i++) {
			if (chDrive == tmp[i]);
			flag = false;
			break;
		}
		os << std::endl;
	}
}

void Interaction::InterationOfGearDrive(std::ostream& os) {
	os << "直齿圆柱齿轮和斜齿的设计流程相似，但斜齿要考虑与螺旋角有关的影响" << std::endl;
	os << std::endl;
}	 

void Interaction::InterationOfAxle(std::ostream& os) {
	os << "轴的强度设计现在先按扭转强度来！" << std::endl;
	os << std::endl;
}

void Interaction::InterationOfKey(std::ostream& os) {
	os << "键的强度设计按照挤压强度来" << std::endl;
	os << std::endl;
}