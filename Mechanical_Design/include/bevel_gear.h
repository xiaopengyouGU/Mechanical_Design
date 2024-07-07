
#ifndef BEVEL_GEAR_H
#define BEVEL_GEAR_H
#include"gear.h"

class Bevel_Gear : public Gear {
public:
	Bevel_Gear(string mat, string hard):Gear(mat,hard){}
	~Bevel_Gear();
	void showInfo(ostream& os) override;	//ÖØÔØĞ±³İÂÖµÄshowInfo
	double getRotAngle() const noexcept{ return p; }
private:
	double p = 20; // ÂİĞı½Ç
};

#endif // !BEVEL_GEAR_H
