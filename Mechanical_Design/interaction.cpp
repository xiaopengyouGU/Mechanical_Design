#include "interaction.h"

void Interaction::setIni(std::ostream&os) {	//��ʼ����������
	os << "************************************************" << std::endl;
	os << "�������ƣ� Mechaniacl_Design" << std::endl;
	os << "���ߣ� Lvtou" << std::endl;
	os << "2024/7/16  CSU" << std::endl;
	os << "��ʼ��ƣ�" << std::endl;
	os << "�ɽ��е����:" << std::endl;
	os << "A �������       B ������" << std::endl;
	os << "************************************************\n" << std::endl;
}

void Interaction::InterationOfTotal(std::ostream& os) {
	os << "��ѡ����Ҫ���е����:" << std::endl;
	os << "A �������		B ������			Q �˳�" << std::endl;
	std::cin >> chTotal;
	while (chTotal != 'A' && chTotal != 'B' && chTotal != 'Q') {
		os << "��������ȷ��ѡ�" << std::endl;
		os << "A �������		B ������			Q �˳�" << std::endl;
		std::cin >> chTotal;
	}
	os << std::endl;
}

void Interaction::InterationOfDriveDesign(std::ostream& os) {
	os << "�ɹ�ѡ��Ĵ���������£�" << std::endl;
	os << "A ֱ���ִ������				B б���ִ������" << std::endl;
	os << "C ���������					D ���������" << std::endl;
	os << "Q �˳��������" << std::endl;
	std::cin >> chDrive;
	char tmp[5] = { 'A', 'B','C','D','Q' };
	bool flag = true;
	for (int i = 0; i < sizeof(tmp); i++) {
		if (chDrive == tmp[i]);
		flag = false;
		break;
	}
	while (flag) {
		os << "��������ȷ��ѡ�" << std::endl;
		os << "A ֱ���ִ������				B б���ִ������" << std::endl;
		os << "C ���������					D ���������" << std::endl;
		os << "Q �˳��������" << std::endl;
		std::cin >> chDrive;
		for (int i = 0; i < sizeof(tmp); i++) {
			if (chDrive == tmp[i]);
			flag = false;
			break;
		}
	}
	os << std::endl;
}

void Interaction::InterationOfPartDesign(std::ostream& os) {
	os << "�ɹ�ѡ������������£�" << std::endl;
	os << "A �������				B ������" << std::endl;
	os << "Q �˳�������" << std::endl;
	std::cin >> chPart;
	char tmp[3] = { 'A', 'B','Q' };
	bool flag = true;
	for (int i = 0; i < sizeof(tmp); i++) {
		if (chDrive == tmp[i]);
		flag = false;
		break;
	}
	while (flag) {
		os << "��������ȷ��ѡ�" << std::endl;
		os << "A �������				B ������" << std::endl;
		os << "Q �˳��������" << std::endl;
		std::cin >> chPart;
		for (int i = 0; i < sizeof(tmp); i++) {
			if (chDrive == tmp[i]);
			flag = false;
			break;
		}
		os << std::endl;
	}
}

void Interaction::InterationOfGearDrive(std::ostream& os) {
	os << "ֱ��Բ�����ֺ�б�ݵ�����������ƣ���б��Ҫ�������������йص�Ӱ��" << std::endl;
	os << std::endl;
}	 

void Interaction::InterationOfAxle(std::ostream& os) {
	os << "���ǿ����������Ȱ�Ťתǿ������" << std::endl;
	os << std::endl;
}

void Interaction::InterationOfKey(std::ostream& os) {
	os << "����ǿ����ư��ռ�ѹǿ����" << std::endl;
	os << std::endl;
}