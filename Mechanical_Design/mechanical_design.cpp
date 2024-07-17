#include "mechanical_design.h"

void Mechanical_Design::startDesign(std::ostream& os) {	//开始设计
	Ite->setIni(os);					//界面初始化
	Ite->InterationOfTotal(os);			//总体设计界面
	char ch1 = Ite->getTotal();			//获取参数
	while (ch1 != 'Q') {
		if (ch1 == 'A') {	//开始传动设计
			startDriveDesign(os);		//传动设计界面
			//进行传动设计
		}
		else if (ch1 == 'B') {
			startPartDesign(os);		//零件设计界面
			//进行零件设计
		}
		else if (ch1 == 'C') {//
			showDesignInfo(os);			//显示设计信息
		}
		Ite->InterationOfTotal(os);		//不能忘了这一步
		ch1 = Ite->getTotal();			//获取回答
	}
	vec->showTotalDesign(true);			//显示所有设计
}

void Mechanical_Design::startDriveDesign(std::ostream& os) {//开始传动设计
	Ite->InterationOfDriveDesign(os);
	char ch2 = Ite->getDrive();
	while (ch2 != 'Q') {
		switch (ch2) {
		case 'A':
			Ite->InterationOfGearDrive(os);
			vec->addDesign(std::make_shared<Spur_Gear_Drive>(true,std::make_shared<Spur_Gear>("40Cr","280HBW"),
				std::make_shared<Spur_Gear>("45钢", "240HBW")));
			break;
		case 'B':
			Ite->InterationOfGearDrive(os);
			vec->addDesign(std::make_shared<Bevel_Gear_Drive>(true,std::make_shared<Bevel_Gear>("40Cr", "280HBW"),
				std::make_shared<Bevel_Gear>("45钢", "240HBW")));
			break;
		default:
			break;
		}
		Ite->InterationOfDriveDesign(os);
		ch2 = Ite->getDrive();		//修改ch2
	}
}

void Mechanical_Design::startPartDesign(std::ostream& os) {
	Ite->InterationOfPartDesign(os);
	char ch3 = Ite->getPart();
	while (ch3 != 'Q') {
		switch (ch3) {
		case 'A':
			Ite->InterationOfKey(os);
			//vec->addDesign(std::make_shared<Key>());
			break;
		case 'B':
			Ite->InterationOfAxle(os);
			//vec->addDesign(std::make_shared<Axle>());
			break;
		default:
			break;
		}
		Ite->InterationOfPartDesign(os);
		ch3 = Ite->getPart();
	}
}

void Mechanical_Design::showDesignInfo(std::ostream& os) {
	Ite->InterationOfInfo(os);
	char ch4 = Ite->getShow();
	int tmp;
	while (ch4 != 'Q') {
		switch (ch4) {
		case 'A':
			vec->showTotalDesign(true);			//详细信息
			break;
		case 'B':
			vec->showTotalDesign(false);		//粗略信息
			break;
		case 'C':
			os << "请输入设计序号 0-" << vec->getSize() << " :" << std::endl;
			std::cin >> tmp;
			vec->showDesign(tmp);
		default:
			break;
		}
		Ite->InterationOfInfo(os);
		ch4 = Ite->getShow();
	}
}