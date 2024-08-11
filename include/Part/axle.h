#pragma once
#ifndef AXLE_H
#define AXLE_H
#include "part.h"
class Axle : public Part {
public:
	Axle(string mat = "45钢调质",string hard = "200HBS"):Part(mat,hard){
		setInfo(std::cout);
	}
	~Axle() {};

	void showInfo(std::ostream& os) override;		

	double getIz() const { return Iz; }
	double getO() const { return O; }
	double getlen() const { return len; }
	double gett() const { return t; }
	double getd() const { return d; }

	void setIz(double val) { Iz = val; }
	void setlen(double val) { len = val; }
	void setO(double val) { O = val; }
	void sett(double val) { t = val; }
	void setd(double val) { d = val; }
 
protected:
	//轴的信息输入
	void setInfo(std::ostream& os);		

	double d;					//轴的直径
	double Iz;					//惯性矩
	double len;					//轴的长度
	double O;					//拉压强度
	double t;					//剪切强度
};
#endif