#pragma once
#ifndef OUTPUTTER_H
#define OUTPUTTER_H
#include <fstream>
#include "design_vec.h"
//��������
//����������
#define DETAILED_OUTPUT

using std::ofstream;
class Outputter {
public:
	Outputter(){};
	~Outputter() {};
	void operator()(string str, Design_Vec& vec) {
		setOutput(str, vec);						//���������()��ʹ�����Ϊ�ɵ��ö���
}	

private:
	void setOutput(string str, Design_Vec& vec);
};
#endif
