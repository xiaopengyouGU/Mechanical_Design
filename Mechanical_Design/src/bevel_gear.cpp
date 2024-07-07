#include "bevel_gear.h"

void Bevel_Gear::showInfo(ostream& os) {
	os << "该斜齿轮的参数如下：" << "\n";
	os << "齿数z = " << Z << "\n";
	os << "宽度b = " << B << "\n";
	os << "螺旋角p = " << p << "\n";
	os << "分度圆直径d = " << d << "\n";
	os << "模数m = " << m << "\n";
	os << "压力角a = " << a << "度" << "\n";
	os << "材料是：" << Material << "\n";
	os << "硬度是：" << Hardness << "\n";
	os << "精度等级Level = " << Level << "\n";
}

Bevel_Gear::~Bevel_Gear() {
	showInfo(std::cout);
}