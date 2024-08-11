#include "key.h"

void Key::showInfo(ostream& os) {
	os << "GB/T 1096" << std::endl;
	os << "平键,A型" << std::endl;
	os << "键宽b：" << b << "mm" << std::endl;
	os << "键高h：" << h << "mm" << std::endl;
	os << "键长L：" << L << "mm" << std::endl;
 }