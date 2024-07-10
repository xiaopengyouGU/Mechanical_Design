#include "mechanical_design.h"

void Mechanical_Design::startDesign(std::ostream& os) {	//开始设计
	Ite->setIni(os);	//界面初始化
	Ite->InterationOfTotal(os);	//总体设计界面
	char ch1 = Ite->getTotal();	//获取参数
	while (ch1 != 'Q') {
		if (ch1 == 'A') {	//开始传动设计
			startDriveDesign(os);	//传动设计界面
			//进行传动设计
		}
		else if (ch1 == 'B') {
			startPartDesign(os);		//零件设计界面
			//进行零件设计
		}
		Ite->InterationOfTotal(os);	//
		ch1 = Ite->getTotal();		//获取回答
	}
	vec->showTotalDesign(true);		//显示所有设计
}

void Mechanical_Design::startDriveDesign(std::ostream& os) {//开始传动设计
	Ite->InterationOfDriveDesign(os);
	char ch2 = Ite->getDrive();
	while (ch2 != 'Q') {
		switch (ch2) {
		case 'A':
			Ite->InterationOfGearDrive(os);
			//vec->addDesign(std::make_shared<Spur_Gear_Drive>());
			break;
		case 'B':
			Ite->InterationOfGearDrive(os);
			//vec->addDesign(std::make_shared<Bevel_Gear_Drive>());
			break;
		default:
			break;
		}
		Ite->InterationOfDriveDesign(os);
		ch2 = Ite->getDrive();//修改ch2
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