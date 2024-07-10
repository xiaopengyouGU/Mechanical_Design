#include "mechanical_design.h"

void Mechanical_Design::startDesign(std::ostream& os) {	//��ʼ���
	Ite->setIni(os);	//�����ʼ��
	Ite->InterationOfTotal(os);	//������ƽ���
	char ch1 = Ite->getTotal();	//��ȡ����
	while (ch1 != 'Q') {
		if (ch1 == 'A') {	//��ʼ�������
			startDriveDesign(os);	//������ƽ���
			//���д������
		}
		else if (ch1 == 'B') {
			startPartDesign(os);		//�����ƽ���
			//����������
		}
		Ite->InterationOfTotal(os);	//
		ch1 = Ite->getTotal();		//��ȡ�ش�
	}
	vec->showTotalDesign(true);		//��ʾ�������
}

void Mechanical_Design::startDriveDesign(std::ostream& os) {//��ʼ�������
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
		ch2 = Ite->getDrive();//�޸�ch2
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