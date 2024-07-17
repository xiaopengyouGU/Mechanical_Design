#include "spur_gear.h"


void Spur_Gear::showInfo(ostream& os) {
	os << "该直齿轮的参数如下：" << std::endl;
	os << "齿数z = " << Z << std::endl;
	os << "宽度b = " << B << "mm" << std::endl;
	os << "分度圆直径d = " << d << "mm" << std::endl;
	os << "模数m = " << m << "mm" << std::endl;
	os << "压力角a = " << a << "度" << std::endl;
	os << "材料是：" << Material << std::endl;
	os << "硬度是：" << Hardness << std::endl;
	os << "精度等级Level = " << Level << "级" << std::endl;
	os << std::endl;	//清空缓冲区
}

Spur_Gear::~Spur_Gear(){

}