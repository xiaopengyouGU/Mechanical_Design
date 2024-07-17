#ifndef SPUR_GEAR_H
#define SPUR_GEAR_H
#include "gear.h"
class Spur_Gear : public Gear {
public:
	Spur_Gear(string mat, string hard):Gear(mat,hard){
		std::cout << "该直齿轮的材料是：" << mat << " " << "硬度是：" << hard <<std::endl;
		std::cout << "请依次输入接触疲劳强度，弯曲疲劳强度，齿数" << std::endl;
		double tmpoh, tmpof, tmpz;
		std::cin >> tmpoh >> tmpof >> tmpz;
		OH = tmpoh, OF = tmpof;
		Z = tmpz;
	}
	Spur_Gear(string mat, string hard, double oh, double of, int z1, double P = 0)
		:Gear(mat, hard, oh, of,z1,P) {}
	~Spur_Gear();

	void showInfo(ostream& os) override;	//这里只重载了Part的showInfo

};

#endif 
