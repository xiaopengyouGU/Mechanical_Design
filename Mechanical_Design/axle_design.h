#pragma once
#ifndef AXLE_DESIGN_H
#define AXLE_DESIGN_H
#include "part_design.h"
#include "axle.h"
//��������Ը��ӣ�ֻ����Ťתǿ��
class Axle_Design : public Part_Design {
public:
	Axle_Design(bool b, shared_ptr<Axle> ptr = nullptr, string load = "����") :
		Part_Design(load), part(ptr) {
		setDesign(b);					//�������
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

	shared_ptr<Axle> part;				//�������
	double P = 10;						//���ݵĹ���Kw
	double n = 93.61;					//ת��
	double T;							//ת��
	double KA = 1.0;					//���㰲ȫϵ��
};
#endif