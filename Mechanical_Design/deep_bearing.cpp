#include "deep_bearing.h"

void Deep_Bearing::showInfo(std::ostream& os) {
	os << "该深沟球轴承的参数如下：" << std::endl;
	os << "内径代号为：" << code << std::endl;
	os << "内径为：" << d << std::endl;
}