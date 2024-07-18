#include "design_vec.h"

void Design_Vec::addDesign(int type) {
	shared_ptr<Design> des;						//����ָ��
	bool flag = true;
#ifdef USER_CHOICE
	flag = false;
#endif // ʹ�ú����

	if (type == DesignVector::SpurGearDrive || type == DesignVector::BevelGearDrive) {	//ֱ���ִ������
		//���ǵ����õķ�װ�Խ���������ŵ�Design_Vec����
		std::string str1, str2, str3, str4;
		std::cout << "Բ�����ִ�����ƣ�" << std::endl;
		std::cout << "���������ֵĲ��Ϻ�Ӳ�ȣ�" << std::endl;
		std::cin >> str1 >> str2;
		std::cout << "������С���ֵĲ��Ϻ�Ӳ�ȣ�" << std::endl;
		std::cin >> str3 >> str4;
		if (type == DesignVector::SpurGearDrive) {
			des = std::make_shared<Spur_Gear_Drive>(flag,
				std::make_shared<Spur_Gear>(str3, str4), std::make_shared<Spur_Gear>(str1, str2));
		}
		else {
			des = std::make_shared<Bevel_Gear_Drive>(flag,
				std::make_shared<Bevel_Gear>(str3, str4), std::make_shared<Bevel_Gear>(str1, str2));
		}
		//des->setDesign(true);				//��ʼ�������,��С���֣��ٴ����
		des->setNum(getSize());				//��ӱ��
		VecPtr.push_back(des);				//��Ӷ���
	}
	else if (type == DesignVector::AxleDesign) {
		//����������
	}
	else if (type == DesignVector::KeyDesign) {
		//���м������
	}
	else if (type == DesignVector::DeepBearingDesign) {
		//���������е����
	}
	else if (type == DesignVector::AngleBearingDesign) {
		//���нǽӴ�����е����
	}
	else if (type == DesignVector::BeltDrive) {
		//���д����������
	}
	else if (type == DesignVector::ChainDrive) {
		//���������������
	}
} 

void Design_Vec::deleteDesign(int pos) {	//ɾ��һ�����
	if (pos >= getSize() || pos < 0) {
		std::cout << "λ�ó���, pos ���� >= 0 ��  < "<< getSize()-1 << std::endl;
	}
	else {
		std::cout << "ɾ��һ��" << VecPtr[pos]->getName() << " " << std::endl;
		VecPtr.erase(VecPtr.begin() + pos);	//ʹ�õ�����
	}
}

void Design_Vec::deleteTotalDesign() {
	//ɾ���������
	VecPtr.clear();
}

void Design_Vec::showDesign(int pos) {
	if (pos >= getSize() || pos < 0) {
		std::cout << "λ�ó���, pos ���� >= 0 ��  < " << getSize()-1 << std::endl;
	}
	else {
		VecPtr[pos]->showDesignInfo(std::cout);	//��ʾ��ϸ���
	}
}

void Design_Vec::showTotalDesign(bool b) {
	if (getSize() == 0)
		std::cout << "��ǰ�����" << std::endl;
	if (!b) {//������ʾ
		for (int i = 0; i < getSize(); i++) {
			std::cout << "��ţ�" << VecPtr[i]->getNum() << " " << 
				"������ƣ�" << VecPtr[i]->getName() << std::endl;
		}						
	}
	else {	//��ϸ��ʾ
		for (int i = 0; i < getSize(); i++) {
			showDesign(i);
		}
	}

}