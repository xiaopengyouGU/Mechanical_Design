#include "outputter.h"

void Outputter::setOutput(string str, Design_Vec& vec) {
	std::ofstream os;								//�����ļ�������
	bool flag = false;
#ifdef DETAILED_OUTPUT
	flag = true;
#endif
	os.open(str, ofstream::out | ofstream::app);	//���������ļ��е�����
	os << "**********************************************" << std::endl;
	vec.showTotalDesign(flag, os);
	os.close();										//�ر��ļ�
}