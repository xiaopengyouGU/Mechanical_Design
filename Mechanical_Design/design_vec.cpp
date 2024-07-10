#include "design_vec.h"

void Design_Vec::addDesign(shared_ptr<Design> des) {
	if (des != nullptr) {
		des->setDesign();		//开始具体设计
		des->setNum(getSize());	//添加编号
		VecPtr.push_back(des);	//添加对象
	}
} 

void Design_Vec::deleteDesign(int pos) {	//删除一个设计
	if (pos >= getSize() || pos < 0) {
		std::cout << "位置出错, pos 必须 >= 0 且  < "<< getSize() << std::endl;
	}
	else {
		std::cout << "删除一个" << VecPtr[pos]->getName() << " " << std::endl;
		VecPtr.erase(VecPtr.begin() + pos);	//使用迭代器
	}
}

void Design_Vec::deleteTotalDesign() {
	//删除所有设计
	VecPtr.clear();		//清空
}

void Design_Vec::showDesign(int pos) {
	if (pos >= getSize() || pos < 0) {
		std::cout << "位置出错, pos 必须 >= 0 且  < " << getSize() << std::endl;
	}
	else {
		VecPtr[pos]->showDesignInfo(std::cout);	//显示详细设计
	}
}

void Design_Vec::showTotalDesign(bool b) {
	if (!b) {
		for (int i = 0; i < getSize(); i++) {
			std::cout << "编号是：" << VecPtr[i]->getNum() <<
				"设计名称是：" << VecPtr[i]->getName() << std::endl;
		}
	}
	else {
		for (int i = 0; i < getSize(); i++) {
			showDesign(i);
		}
	}

}