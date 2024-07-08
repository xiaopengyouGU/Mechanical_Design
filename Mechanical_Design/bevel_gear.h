
#ifndef BEVEL_GEAR_H
#define BEVEL_GEAR_H
#include"gear.h"

class Bevel_Gear : public Gear {
public:
	Bevel_Gear(string mat, string hard):Gear(mat,hard){}
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
	double at = 20;		//端面压力角
	double an = 20;    //法面压力角 tan(an) = tan(at)*cos(p)
	double pb = 20;    //基圆螺旋角 tan(pb) = tan(p)*cos(at)
};

#endif // !BEVEL_GEAR_H
