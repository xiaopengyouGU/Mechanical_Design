#include "design_vec.h"

void Design_Vec::addDesign(int type) {
	shared_ptr<Design> des = nullptr;			//智能指针
	bool flag = true;
#ifdef USER_CHOICE
	flag = false;
#endif // 使用宏控制

	if (type == DesignVector::SpurGearDrive || type == DesignVector::BevelGearDrive) {	//直齿轮传动设计
		//考虑到更好的封装性将参数输入放到Design_Vec类中
		std::string str1, str2, str3, str4;
		std::cout << "圆柱齿轮传动设计：" << std::endl;
		std::cout << "请输入大齿轮的材料和硬度：" << std::endl;
		std::cin >> str1 >> str2;
		std::cout << "请输入小齿轮的材料和硬度：" << std::endl;
		std::cin >> str3 >> str4;
		if (type == DesignVector::SpurGearDrive) {
			des = std::make_shared<Spur_Gear_Drive>(flag,
				std::make_shared<Spur_Gear>(str3, str4), std::make_shared<Spur_Gear>(str1, str2));
		}
		else {
			des = std::make_shared<Bevel_Gear_Drive>(flag,
				std::make_shared<Bevel_Gear>(str3, str4), std::make_shared<Bevel_Gear>(str1, str2));
		}
		//des->setDesign(true);				//开始具体设计,先小齿轮，再大齿轮
	}
	else if (type == DesignVector::AxleDesign) {
		des = std::make_shared<Axle_Design>(flag, std::make_shared<Axle>());
	}
	else if (type == DesignVector::KeyDesign) {
		des = std::make_shared<Key_Design>(flag,"静载荷");
	}
	else if (type == DesignVector::DeepBearingDesign) {
		des = std::make_shared<Bearing_Design>(flag, std::make_shared<Deep_Bearing>());
		des->setName("深沟球轴承设计");
	}
	else if (type == DesignVector::AngleBearingDesign) {
		des = std::make_shared<Bearing_Design>(flag, std::make_shared<Angle_Bearing>());
		des->setName("角接触球轴承设计");
	}
	else if (type == DesignVector::BeltDrive) {
		//进行带传动的设计
	}
	else if (type == DesignVector::ChainDrive) {
		//进行链传动的设计
	}

	if (des != nullptr) {
		des->setNum(getSize());				//添加编号
		VecPtr.push_back(des);				//添加对象
	}
} 

void Design_Vec::deleteDesign(int pos) {	//删除一个设计
	if (pos >= getSize() || pos < 0) {
		std::cout << "位置出错, pos 必须 >= 0 且  < "<< getSize()-1 << std::endl;
	}
	else {
		std::cout << "删除一个" << VecPtr[pos]->getName() << " " << std::endl;
		VecPtr.erase(VecPtr.begin() + pos);	//使用迭代器
		//重新修改编号
		for (int i = 0; i < VecPtr.size(); i++) {
			VecPtr[i]->setNum(i);
		}
	}
}

void Design_Vec::deleteTotalDesign() {
	//删除所有设计
	VecPtr.clear();
}

void Design_Vec::showDesign(int pos) {
	if (pos >= getSize() || pos < 0) {
		std::cout << "位置出错, pos 必须 >= 0 且  < " << getSize()-1 << std::endl;
	}
	else {
		VecPtr[pos]->showDesignInfo(std::cout);	//显示详细设计
	}
}

void Design_Vec::showTotalDesign(bool b) {
	if (getSize() == 0)
		std::cout << "当前无设计" << std::endl;
	if (!b) {//粗略显示
		for (int i = 0; i < getSize(); i++) {
			std::cout << "编号：" << VecPtr[i]->getNum() << " " << 
				"设计名称：" << VecPtr[i]->getName() << std::endl;
		}						
	}
	else {	//详细显示
		for (int i = 0; i < getSize(); i++) {
			showDesign(i);
		}
	}

}