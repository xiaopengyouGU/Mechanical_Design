#ifndef SPUR_GEAR_H
#define SPUR_GEAR_H
#include "gear.h"
class Spur_Gear : public Gear {
public:
	Spur_Gear(string mat, string hard):Gear(mat,hard){}
	Spur_Gear(string mat, string hard, double oh, double of, int z1, double P = 0)
		:Gear(mat, hard, oh, of,z1,P) {}
	~Spur_Gear();
	void showInfo(ostream& os) override;	//������Part��showInfo

};

#endif // !SPUR_GEAR_H
