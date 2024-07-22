#include "interaction.h"

void Interaction::setIni(std::ostream&os) {	//初始化界面设置
	os << "************************************************" << std::endl;
	os << "程序名称： Mechaniacl_Design" << std::endl;
	os << "作者： Lvtou" << std::endl;
	os << "2024/7/21  CSU" << std::endl;
	os << "开始设计：" << std::endl;
	os << "可进行的设计:" << std::endl;
	os << "A 传动设计       B 零件设计" << std::endl;
	os << "************************************************\n" << std::endl;
}

void Interaction::InteractionOfTotal(std::ostream& os) {
	os << "请选择您要进行的操作:" << std::endl;
	os << "A 传动设计				B 零件设计" << std::endl;
	os << "C 设计操作				Q 退出" << std::endl;
	std::cin >> chTotal;
	while (chTotal != 'A' && chTotal != 'B' && chTotal != 'Q' && chTotal != 'C') {
		os << "请输入正确的选项：" << std::endl;
		os << "A 传动设计				B 零件设计" << std::endl;
		os << "C 设计操作				Q 退出" << std::endl;
		std::cin >> chTotal;
	}
	os << std::endl;
}

void Interaction::InteractionOfDriveDesign(std::ostream& os) {
	os << "可供选择的传动设计如下：" << std::endl;
	os << "A 直齿轮传动设计				B 斜齿轮传动设计" << std::endl;
	os << "C 带传动设计					D 链传动设计" << std::endl;
	os << "Q 退出传动设计" << std::endl;
	std::cin >> chDrive;
	char tmp[5] = { 'A', 'B','C','D','Q' };
	bool flag = true;
	for (int i = 0; i < sizeof(tmp); i++) {
		if (chDrive == tmp[i]) {
			flag = false;
			break;
		}
	}
	while (flag) {
		os << "请输入正确的选项：" << std::endl;
		os << "A 直齿轮传动设计				B 斜齿轮传动设计" << std::endl;
		os << "C 带传动设计					D 链传动设计" << std::endl;
		os << "Q 退出传动设计" << std::endl;
		std::cin >> chDrive;
		for (int i = 0; i < sizeof(tmp); i++) {
			if (chDrive == tmp[i]) {
				flag = false;
				break;
			}
		}
	}
	os << std::endl;
}

void Interaction::InteractionOfPartDesign(std::ostream& os) {
	os << "可供选择的零件设计如下：" << std::endl;
	os << "A 平键的设计				B 轴的设计" << std::endl;
	os << "C 深沟球轴承的设计			D 角接触球轴承的设计" << std::endl;
	os << "Q 退出零件设计" << std::endl;
	std::cin >> chPart;
	char tmp[5] = { 'A', 'B','Q','C','D'};
	bool flag = true;
	for (int i = 0; i < sizeof(tmp); i++) {
		if (chPart == tmp[i]) {
			flag = false;
			break;
		}
	}
	while (flag) {
		os << "请输入正确的选项：" << std::endl;
		os << "A 平键的设计				B 轴的设计" << std::endl;
		os << "C 深沟球轴承的设计			D 角接触球轴承的设计" << std::endl;
		os << "Q 退出零件设计" << std::endl;
		std::cin >> chPart;
		for (int i = 0; i < sizeof(tmp); i++) {
			if (chPart == tmp[i]) {
				flag = false;
				break;
			}
		}
		os << std::endl;
	}
}

void Interaction::InteractionOfGearDrive(std::ostream& os) {
	os << "直齿圆柱齿轮传动和斜齿差不多，但斜齿要考虑螺旋角的影响" << std::endl;
	os << std::endl;
}	 

void Interaction::InteractionOfAxle(std::ostream& os) {
	os << "轴的强度设计现在先按扭转强度来！" << std::endl;
	os << std::endl;
}

void Interaction::InteractionOfKey(std::ostream& os) {
	os << "键的强度设计按照挤压强度来，使用平键" << std::endl;
	os << std::endl;
}

void Interaction::InteractionOfInfo(std::ostream& os) {
	os << "请选择要进行的操作：" << std::endl;
	os << "A 显示详细设计信息		B 显示粗略设计信息" << std::endl;
	os << "C 显示单个零件的信息 		D 删除所有设计" << std::endl;
	os << "E 删除单个设计			F 将设计信息保存到文件" << std::endl;
	os << "Q 退出设计操作" << std::endl;
	std::cin >> chShow;
	char tmp[7] = { 'A', 'B','Q','C','D','E','F'};
	bool flag = true;
	for (int i = 0; i < sizeof(tmp); i++) {
		if (chShow == tmp[i]) {
			flag = false;
			break;
		}
	}
	while (flag) {
		os << "请输入正确的选项：" << std::endl;
		os << "A 显示详细设计信息		B 显示粗略设计信息" << std::endl;
		os << "C 显示单个零件的信息 		D 删除所有设计" << std::endl;
		os << "E 删除单个设计			F 将设计信息保存到文件" << std::endl;
		os << "Q 退出设计操作" << std::endl;
		std::cin >> chShow;
		for (int i = 0; i < sizeof(tmp); i++) {
			if (chShow == tmp[i]) {
				flag = false;
				break;
			}
		}
	}
	os << std::endl;
}

void Interaction::InteractionOfBearing(std::ostream& os) {
	os << "深沟球轴承和角接触球轴承是两种典型的轴承" << std::endl;
	os << std::endl;
}

void Interaction::InteractionOfChainDrive(std::ostream& os) {
	os << "链传动可以在恶劣的环境下工作" << std::endl;
	os << std::endl;
}

void Interaction::InteractionOfBeltDrive(std::ostream& os) {
	os << "带传动具有过载保护的特点" << std::endl;
	os << std::endl;
}