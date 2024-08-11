#define _CRT_SECURE_NO_WARNINGS
#include "key_design.h"

void Key_Design::setDesign(bool b) {
	Name = "ƽ�����";
	part = std::make_shared<Key>();		//�����ڴ棬�����������
	if (b)
		setDefault();					//Ĭ�ϲ������
	else
		setUserChoice(std::cout);		//�û��������
	testStrength(std::cout);			//У��ǿ��
}

void Key_Design::setUserChoice(ostream& os) {	//ȷ��������Ϣ
	double tmpd, tmpb, tmpT, tmpbs, tmpL;
	string str;
	os << "���������ֱ����" << std::endl;
	std::cin >> tmpd;
	setd(tmpd);
	os << "��������챵Ŀ�ȣ�" << std::endl;
	std::cin >> tmpb;
	setb(tmpb);
	os << "�������贫�ݵ�ת�أ�" << std::endl;
	std::cin >> tmpT;
	setT(tmpT);
	os << "�������غɵ�����(���غɣ���΢��������): " << std::endl;
	std::cin >> str;							//ֱ������LoadҲ��
	setLoad(str);								
	os << "�����غɶ�Ӧ�����ü�ѹӦ���ֱ�Ϊ��" << std::endl;
	os << "���غ� 120-150	\t��΢���100-120	\t���60-90" << std::endl;
	os << "�������Ӧ�����ü�ѹӦ����" << std::endl;
	std::cin >> tmpbs;
	setbs(tmpbs);
	setKeybandh(os);							//ȷ�������ͼ���
	showPossibleL(os);							//������ĳ���ϵ��
	os << "��������ĳ���L: " << std::endl;
	std::cin >> tmpL;
	part->setL(tmpL);
}

void Key_Design::setDefault() {
	//ɶ������
}

void Key_Design::testStrength(std::ostream& os) {	//ǿ��У��
	double h = part->geth(), l = part->getl(), b = part->getb();
	double tmpbs = 4000.0 * T / (h * l * d), tmp;
	while (tmpbs > bs) {
		os << "��ǰ��ѹӦ��Ϊ��" << tmpbs << "Mpa" << std::endl;
		os << "���ӵļ�ѹǿ�Ȳ��������ᱻѹ����" << std::endl;
		os << "��������ĳ���L��ԭʼֵ:" << part->getL() << std::endl;
		showPossibleL(os);							//��ʾ���ĳ�������
		std::cin >> tmp;
		part->setL(tmp);
		l = tmp - b;						//������Ч����
		tmpbs = 4000.0 * T / (h * l * d), tmp;
	}
	os << "����ǿ���㹻!" << std::endl;
}

void Key_Design::showPossibleL(std::ostream& os) {
	os << "���ĳ���ϵ��L: " << std::endl;
	os << "6, 8, 10, 12, 14, 16, 18, 20, 22, 25, 28, 32, 36" << std::endl;
	os << "40, 45, 50, 56, 63, 70, 80, 90, 100, 110, 125, 140" << std::endl;
	os << "160, 180, 200, 250, 280, 320, 360, ..." << std::endl;
}

void Key_Design::showDesignInfo(std::ostream & os) {
	os << "ƽ������Ҫ��Ʋ������£�" << std::endl;
	os << "�غ����� ��" << Load << std::endl;
	part->showInfo(os);
	time(&timer);
	os << "��Ʊ�ţ�" << Num << std::endl;
	os << "��ǰʱ�䣺" << ctime(&timer) << std::endl;
}

void Key_Design::setKeybandh(std::ostream&os) {	//ȷ���������ղ���
	double b = 8, h = 7;
	if (d <= 8) {
		b = 2, h = 2;
		os << "���ĳ��ȷ�Χ��6-20" << std::endl;
	}
	else if (d <= 10) {
		b = 3, h = 3;
		os << "���ĳ��ȷ�Χ��6-36" << std::endl;
	}
	else if (d <= 12) {
		b = 4, h = 4;
		os << "���ĳ��ȷ�Χ��8-45" << std::endl;
	}
	else if (d <= 17) {
		b = 5, h = 5;
		os << "���ĳ��ȷ�Χ��10-56" << std::endl;
	}
	else if (d <= 22) {
		b = 6, h = 6;
		os << "���ĳ��ȷ�Χ��14-70" << std::endl;
	}
	else if (d <= 30) {
		b = 8, h = 7;
		os << "���ĳ��ȷ�Χ��18-90" << std::endl;
	}
	else if (d <= 38) {
		b = 10, h = 8;
		os << "���ĳ��ȷ�Χ��22-110" << std::endl;
	}
	else if (d <= 44) {
		b = 12, h = 8;
		os << "���ĳ��ȷ�Χ��28-140" << std::endl;
	}
	else if (d <= 50) {
		b = 14, h = 9;
		os << "���ĳ��ȷ�Χ��36-160" << std::endl;
	}
	else if (d <= 58) {
		b = 16, h = 10;
		os << "���ĳ��ȷ�Χ��45-180" << std::endl;
	}
	else if (d <= 65) {
		b = 18, h = 11;
		os << "���ĳ��ȷ�Χ��50-200" << std::endl;
	}
	else if (d <= 75) {
		b = 20, h = 12;
		os << "���ĳ��ȷ�Χ��56-220" << std::endl;
	}
	else if (d <= 85) {
		b = 22, h = 14;
		os << "���ĳ��ȷ�Χ��63-250" << std::endl;
	}
	else if (d <= 95) {
		b = 25, h = 14;
		os << "���ĳ��ȷ�Χ��70-280" << std::endl;
	}
	else if (d <= 110) {
		b = 28, h = 16;
		os << "���ĳ��ȷ�Χ��80-320" << std::endl;
	}
	else if (d <= 130) {
		b = 32, h = 18;
		os << "���ĳ��ȷ�Χ��90-360" << std::endl;
	}
	part->setb(b), part->seth(h);				//����ͼ���ȷ��
}