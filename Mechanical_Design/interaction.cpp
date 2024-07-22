#include "interaction.h"

void Interaction::setIni(std::ostream&os) {	//��ʼ����������
	os << "************************************************" << std::endl;
	os << "�������ƣ� Mechaniacl_Design" << std::endl;
	os << "���ߣ� Lvtou" << std::endl;
	os << "2024/7/21  CSU" << std::endl;
	os << "��ʼ��ƣ�" << std::endl;
	os << "�ɽ��е����:" << std::endl;
	os << "A �������       B ������" << std::endl;
	os << "************************************************\n" << std::endl;
}

void Interaction::InteractionOfTotal(std::ostream& os) {
	os << "��ѡ����Ҫ���еĲ���:" << std::endl;
	os << "A �������				B ������" << std::endl;
	os << "C ��Ʋ���				Q �˳�" << std::endl;
	std::cin >> chTotal;
	while (chTotal != 'A' && chTotal != 'B' && chTotal != 'Q' && chTotal != 'C') {
		os << "��������ȷ��ѡ�" << std::endl;
		os << "A �������				B ������" << std::endl;
		os << "C ��Ʋ���				Q �˳�" << std::endl;
		std::cin >> chTotal;
	}
	os << std::endl;
}

void Interaction::InteractionOfDriveDesign(std::ostream& os) {
	os << "�ɹ�ѡ��Ĵ���������£�" << std::endl;
	os << "A ֱ���ִ������				B б���ִ������" << std::endl;
	os << "C ���������					D ���������" << std::endl;
	os << "Q �˳��������" << std::endl;
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
		os << "��������ȷ��ѡ�" << std::endl;
		os << "A ֱ���ִ������				B б���ִ������" << std::endl;
		os << "C ���������					D ���������" << std::endl;
		os << "Q �˳��������" << std::endl;
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
	os << "�ɹ�ѡ������������£�" << std::endl;
	os << "A ƽ�������				B ������" << std::endl;
	os << "C �����е����			D �ǽӴ�����е����" << std::endl;
	os << "Q �˳�������" << std::endl;
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
		os << "��������ȷ��ѡ�" << std::endl;
		os << "A ƽ�������				B ������" << std::endl;
		os << "C �����е����			D �ǽӴ�����е����" << std::endl;
		os << "Q �˳�������" << std::endl;
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
	os << "ֱ��Բ�����ִ�����б�ݲ�࣬��б��Ҫ���������ǵ�Ӱ��" << std::endl;
	os << std::endl;
}	 

void Interaction::InteractionOfAxle(std::ostream& os) {
	os << "���ǿ����������Ȱ�Ťתǿ������" << std::endl;
	os << std::endl;
}

void Interaction::InteractionOfKey(std::ostream& os) {
	os << "����ǿ����ư��ռ�ѹǿ������ʹ��ƽ��" << std::endl;
	os << std::endl;
}

void Interaction::InteractionOfInfo(std::ostream& os) {
	os << "��ѡ��Ҫ���еĲ�����" << std::endl;
	os << "A ��ʾ��ϸ�����Ϣ		B ��ʾ���������Ϣ" << std::endl;
	os << "C ��ʾ�����������Ϣ 		D ɾ���������" << std::endl;
	os << "E ɾ���������			F �������Ϣ���浽�ļ�" << std::endl;
	os << "Q �˳���Ʋ���" << std::endl;
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
		os << "��������ȷ��ѡ�" << std::endl;
		os << "A ��ʾ��ϸ�����Ϣ		B ��ʾ���������Ϣ" << std::endl;
		os << "C ��ʾ�����������Ϣ 		D ɾ���������" << std::endl;
		os << "E ɾ���������			F �������Ϣ���浽�ļ�" << std::endl;
		os << "Q �˳���Ʋ���" << std::endl;
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
	os << "�����кͽǽӴ�����������ֵ��͵����" << std::endl;
	os << std::endl;
}

void Interaction::InteractionOfChainDrive(std::ostream& os) {
	os << "�����������ڶ��ӵĻ����¹���" << std::endl;
	os << std::endl;
}

void Interaction::InteractionOfBeltDrive(std::ostream& os) {
	os << "���������й��ر������ص�" << std::endl;
	os << std::endl;
}