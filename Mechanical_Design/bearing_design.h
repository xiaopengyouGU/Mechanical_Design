#pragma once
#ifndef BEARING_DESIGN_H
#define BEARING_DESIGN_H
#include "part_design.h"
#include "bearing.h"
class Bearing_Design : public Part_Design {
public:
	Bearing_Design(string load = "动载荷") :Part_Design(load) {}
	Bearing_Design(bool b, shared_ptr<Bearing> p = nullptr, string load = "动载荷")
		:Part_Design(load), part(p) {
		setDesign(b);
	}
	~Bearing_Design() {};

	void setDesign(bool b) override;
	void showDesignInfo(ostream& os) override;	//直接重载该函数

protected:
	void setFr(double val) { Fr = val; }
	void setFa(double val) { Fa = val; }
	void setX(double val) { X = val; }
	void setY(double val) { Y = val; }
	void setP(double val) { P = val; }
	void setCo(double val) { Co = val; }
	void setfd(double val) { fd = val; }
	void setft(double val) { ft = val; }
	void setLh(double val) { Lh = val; }
	void setn(double val) { n = val; }
	void sete(double val) { e = val; }
	void setCd(double val) { Cd = val; }

	void testC(ostream&os);						//验算当量动载荷
	void setXandY();							//用插值法确定X和Y,只支持70000AC和深沟球轴承
	void setUserChoice(ostream&os);
	void setDefault() override;					//默认操作
	void setBasicParameter(ostream& os);		//默认参数设定
	void setBearingParameter(ostream& os);		//轴承参数设定

	shared_ptr<Bearing> part;					//零件对象，一次只设计一个轴承
	double Fr = 5500;							//径向力
	double Fa = 2700;							//轴向力
	double X = 1;								//径向动载荷系数
	double Y = 0;								//轴向动载荷系数
	double P = 0;								//当量动载荷
	double Cd = 61800;							//基本额定动载荷,25.5KN
	double Co = 38000;							//基本额定静载荷
	double fd = 1.2;							//动载系数
	double ft = 1.0;							//温度系数，默认为1.00, 120度以下
	double Lh = 5000;							//轴承寿命 1x10^6为基数
	double c = 3;								//指数 L = (C/P)^c
	double e = 0.44;							//判断系数
	double n = 1250;							//轴承的转速

};
#endif