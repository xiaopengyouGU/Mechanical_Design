#include "part.h"
//分离式编译

void Part::showInfo(ostream& os) {
	os << "设计零件" << std::endl;
	os << "零件的材料是：" << getMaterial() << std::endl;
}