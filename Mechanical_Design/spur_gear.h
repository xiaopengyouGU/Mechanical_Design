#ifndef SPUR_GEAR_H
#define SPUR_GEAR_H
#include "gear.h"
class Spur_Gear : public Gear {
public:
	Spur_Gear(string mat, string hard):Gear(mat,hard){}
	~Spur_Gear();
	void showInfo(ostream& os) override;	//÷ÿ‘ÿ¡ÀPartµƒshowInfo

};

#endif // !SPUR_GEAR_H
