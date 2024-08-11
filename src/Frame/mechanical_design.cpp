#include "mechanical_design.h"

void Mechanical_Design::startDesign(std::ostream& os) {	//��ʼ���
	Ite->setIni(os);					//�����ʼ��
	Ite->InteractionOfTotal(os);			//������ƽ���
	char ch1 = Ite->getTotal();			//��ȡ����
	while (ch1 != 'Q') {
		if (ch1 == 'A') {	//��ʼ�������
			startDriveDesign(os);		//������ƽ���
			//���д������
		}
		else if (ch1 == 'B') {
			startPartDesign(os);		//�����ƽ���
			//����������
		}
		else if (ch1 == 'C') {//
			showDesignInfo(os);			//��ʾ�����Ϣ
		}
		Ite->InteractionOfTotal(os);		//����������һ��
		ch1 = Ite->getTotal();			//��ȡ�ش�
	}
	vec->showTotalDesign(true);			//��ʾ�������
}

void Mechanical_Design::startDriveDesign(std::ostream& os) {//��ʼ�������
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
		ch2 = Ite->getDrive();		//�޸�ch2
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
			vec->showTotalDesign(true);			//��ϸ��Ϣ
			break;
		case 'B':
			vec->showTotalDesign(false);		//������Ϣ
			break;
		case 'C':								//���������Ϣ
			if (vec->getSize() == 0) {
				os << "��ǰ�����" << std::endl;
			}
			else {
				os << "������������ 0-" << vec->getSize()-1<< " :" << std::endl;
				std::cin >> tmp;
				vec->showDesign(tmp);
			}
			break;
		case 'D':
			os << "ɾ���������" << std::endl;
			vec->deleteTotalDesign();
			break;
		case 'E':
			if (vec->getSize() == 0) {
				os << "��ǰ�����" << std::endl;
			}
			else {
				os << "������������ 0-" << vec->getSize() -1<< " :" << std::endl;
				std::cin >> tmp;
				vec->deleteDesign(tmp);
			}
			break;
		case 'F':
			os << "������Ҫ������ļ�����" << std::endl;
			std::cin >> str;
			output(str + ".txt", *vec);		//���������Ϣ
			break;
		default:
			break;
		}
		Ite->InteractionOfInfo(os);
		ch4 = Ite->getShow();
	}
}