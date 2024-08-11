#include "outputter.h"

void Outputter::setOutput(string str, Design_Vec& vec) {
	std::ofstream os;								//创建文件流对象
	bool flag = false;
#ifdef DETAILED_OUTPUT
	flag = true;
#endif
	os.open(str, ofstream::out | ofstream::app);	//保留被打开文件中的数据
	os << "**********************************************" << std::endl;
	vec.showTotalDesign(flag, os);
	os.close();										//关闭文件
}