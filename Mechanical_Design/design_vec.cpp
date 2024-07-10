#include "design_vec.h"

void Design_Vec::addDesign(shared_ptr<Design> des) {
	if (des != nullptr) {
		des->setDesign();		//��ʼ�������
		des->setNum(getSize());	//��ӱ��
		VecPtr.push_back(des);	//��Ӷ���
	}
} 

void Design_Vec::deleteDesign(int pos) {	//ɾ��һ�����
	if (pos >= getSize() || pos < 0) {
		std::cout << "λ�ó���, pos ���� >= 0 ��  < "<< getSize() << std::endl;
	}
	else {
		std::cout << "ɾ��һ��" << VecPtr[pos]->getName() << " " << std::endl;
		VecPtr.erase(VecPtr.begin() + pos);	//ʹ�õ�����
	}
}

void Design_Vec::deleteTotalDesign() {
	//ɾ���������
	VecPtr.clear();		//���
}

void Design_Vec::showDesign(int pos) {
	if (pos >= getSize() || pos < 0) {
		std::cout << "λ�ó���, pos ���� >= 0 ��  < " << getSize() << std::endl;
	}
	else {
		VecPtr[pos]->showDesignInfo(std::cout);	//��ʾ��ϸ���
	}
}

void Design_Vec::showTotalDesign(bool b) {
	if (!b) {
		for (int i = 0; i < getSize(); i++) {
			std::cout << "����ǣ�" << VecPtr[i]->getNum() <<
				"��������ǣ�" << VecPtr[i]->getName() << std::endl;
		}
	}
	else {
		for (int i = 0; i < getSize(); i++) {
			showDesign(i);
		}
	}

}