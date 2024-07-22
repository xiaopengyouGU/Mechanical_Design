#include "mechanical_design.h"

void Mechanical_Design::startDesign(std::ostream& os) {	//开始设计
	Ite->setIni(os);					//界面初始化
	Ite->InteractionOfTotal(os);			//总体设计界面
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
		Ite->InteractionOfTotal(os);		//不能忘了这一步
		ch1 = Ite->getTotal();			//获取回答
	}
	vec->showTotalDesign(true);			//显示所有设计
}

void Mechanical_Design::startDriveDesign(std::ostream& os) {//开始传动设计
	Ite->InteractionOfDriveDesign(os);
	char ch2 = Ite->getDrive();
	while (ch2 != 'Q') {
		switch (ch2) {
		case 'A':
			Ite->InteractionOfGearDrive(os);
			vec->addDesign(Design_Vec::DesignVector::SpurGearDrive);
			break;
		case 'B':
			Ite->InteractionOfGearDrive(os);
			vec->addDesign(Design_Vec::DesignVector::BevelGearDrive);
			break;
		case 'C':
			Ite->InteractionOfBeltDrive(os);
			vec->addDesign(Design_Vec::DesignVector::BeltDrive);
			break;
		case 'D':
			Ite->InteractionOfChainDrive(os);
			vec->addDesign(Design_Vec::DesignVector::ChainDrive);
		default:
			break;
		}
		Ite->InteractionOfDriveDesign(os);
		ch2 = Ite->getDrive();		//修改ch2
	}
}

void Mechanical_Design::startPartDesign(std::ostream& os) {
	Ite->InteractionOfPartDesign(os);
	char ch3 = Ite->getPart();
	while (ch3 != 'Q') {
		switch (ch3) {
		case 'A':
			Ite->InteractionOfKey(os);
			vec->addDesign(Design_Vec::DesignVector::KeyDesign);
			break;
		case 'B':
			Ite->InteractionOfAxle(os);
			vec->addDesign(Design_Vec::DesignVector::AxleDesign);
			break;
		case 'C':
			Ite->InteractionOfBearing(os);
			vec->addDesign(Design_Vec::DesignVector::DeepBearingDesign);
			break;
		case 'D':
			Ite->InteractionOfBearing(os);
			vec->addDesign(Design_Vec::DesignVector::AngleBearingDesign);
		default:
			break;
		}
		Ite->InteractionOfPartDesign(os);
		ch3 = Ite->getPart();
	}
}

void Mechanical_Design::showDesignInfo(std::ostream& os) {
	Ite->InteractionOfInfo(os);
	char ch4 = Ite->getShow();
	string str = "design";
	int tmp;
	while (ch4 != 'Q') {
		switch (ch4) {
		case 'A':
			vec->showTotalDesign(true);			//详细信息
			break;
		case 'B':
			vec->showTotalDesign(false);		//粗略信息
			break;
		case 'C':								//单个设计信息
			if (vec->getSize() == 0) {
				os << "当前无设计" << std::endl;
			}
			else {
				os << "请输入设计序号 0-" << vec->getSize()-1<< " :" << std::endl;
				std::cin >> tmp;
				vec->showDesign(tmp);
			}
			break;
		case 'D':
			os << "删除所有设计" << std::endl;
			vec->deleteTotalDesign();
			break;
		case 'E':
			if (vec->getSize() == 0) {
				os << "当前无设计" << std::endl;
			}
			else {
				os << "请输入设计序号 0-" << vec->getSize() -1<< " :" << std::endl;
				std::cin >> tmp;
				vec->deleteDesign(tmp);
			}
			break;
		case 'F':
			os << "请输入要保存的文件名：" << std::endl;
			std::cin >> str;
			output(str + ".txt", *vec);		//保存设计信息
			break;
		default:
			break;
		}
		Ite->InteractionOfInfo(os);
		ch4 = Ite->getShow();
	}
}