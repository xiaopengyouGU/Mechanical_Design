#pragma once
#ifndef OUTPUTTER_H
#define OUTPUTTER_H
#include <fstream>
#include "design_vec.h"
//结果输出类
//控制输出结果
#define DETAILED_OUTPUT

using std::ofstream;
class Outputter {
public:
	Outputter(){};
	~Outputter() {};
	void operator()(string str, Design_Vec& vec) {
		setOutput(str, vec);						//重载运算符()，使该类成为可调用对象
}	

private:
	void setOutput(string str, Design_Vec& vec);
};
#endif
