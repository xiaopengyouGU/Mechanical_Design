#pragma once
#ifndef BEARING_H
#define BEARING_H
#include "part.h"
//轴承抽象基类
class Bearing : public Part {
public:
	Bearing(string mat = "轴承钢", string hard = "60HRC"):Part(mat,hard){}
	~Bearing() {};

	//void showInfo(ostream& os) override;		//重载

	string getCode()const { return code; }
	string gettype()const { return type; }
	int getd() const { return d; }

	void setInfo(ostream& os);					//确定内径及代号
	void setd(int val) { d = val; }							//确定内径
	void setCode(string str) { code = str; }
	void settype(string str) { type = str; }
protected:
	string code  = "10";						//内径代号
	string type = "深沟球轴承";					//轴承型号
	int d = 50;									//内径
};

class Deep_Bearing : public Bearing {
public:
	Deep_Bearing(string mat = "轴承钢", string hard = "60HRC") :Bearing(mat, hard) {}
	~Deep_Bearing() {};

	void showInfo(ostream& os) override;		//重载
};

class Angle_Bearing : public Bearing {
public:
	Angle_Bearing(string mat = "轴承钢", string hard = "60HRC") :Bearing(mat, hard) {
		type = "角接触球轴承AC";
	}
	~Angle_Bearing() {};

	void showInfo(ostream& os) override;		//重载
};
#endif