#include "key.h"

void Key::showInfo(ostream& os) {
	os << "GB/T 1096" << std::endl;
	os << "ƽ��,A��" << std::endl;
	os << "����b��" << b << "mm" << std::endl;
	os << "����h��" << h << "mm" << std::endl;
	os << "����L��" << L << "mm" << std::endl;
 }