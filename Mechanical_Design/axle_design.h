#pragma once
#ifndef AXLE_DESIGN_H
#define AXLE_DESIGN_H
#include "part_design.h"
#include "axle.h"
//轴的设计相对复杂，只核算扭转强度
class Axle_Design : public Part_Design {
public:
	Axle_Design(bool b, shared_ptr<Axle> ptr = nullptr, string load = "静载") :
		Part_Design(load), part(ptr) {
		setDesign(b);					//启动设计
	}
	~Axle_Design() {};

	void showDesignInfo(std::ostream& os) override;
	void setDesign(bool b)override;

protected:
	void setDefault() override;
	void setUserChoice(std::ostream& os) override;
	void testt(std::ostream&os);
	void setP(double val) { P = val; }
	void setn(double val) { n = val; }
	void setT(double val) { T = val; }
	void setKA(double val) { KA = val; }

	shared_ptr<Axle> part;				//零件对象
	double P = 10;						//传递的功率Kw
	double n = 93.61;					//转速
	double T;							//转矩
	double KA = 1.0;					//计算安全系数
};
#endif