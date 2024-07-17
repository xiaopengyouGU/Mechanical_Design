
#ifndef BEVEL_GEAR_H
#define BEVEL_GEAR_H
#include"gear.h"

class Bevel_Gear : public Gear {
public:
	Bevel_Gear(string mat, string hard) :Gear(mat, hard) {
		std::cout << "该齿轮的材料是：" << mat << "硬度是：" << hard << std::endl;
		std::cout << "请依次输入接触疲劳强度，弯曲疲劳强度，齿数，螺旋角" << std::endl;
		double tmpoh, tmpof, tmpz, tmpp;
		std::cin >> tmpoh >> tmpof >> tmpz >> tmpp;
		OH = tmpoh, OF = tmpof;
		Z = tmpz, p = tmpp;
	}
	Bevel_Gear(string mat, string hard,double oh,double of,int z1,double P = 14):
		Gear(mat,hard,oh,of,z1,P){}
	~Bevel_Gear();

	void showInfo(ostream& os) override;	//重载斜齿轮的showInfo

	double getRotAngle() const noexcept{ return p; }
	double getat() const { return at; }		
	double getpb() const { return pb; }
	double getan() const { return an; }

	void setat(double val) { at = val; }
	void setpb(double val) { pb = val; }
	void setan(double val) { an = val; }
private:
	double at = 20;							//端面压力角
	double an = 20;							//法面压力角 tan(an) = tan(at)*cos(p)
	double pb = 20;							//基圆螺旋角 tan(pb) = tan(p)*cos(at)
};

#endif
