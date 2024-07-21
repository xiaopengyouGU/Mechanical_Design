#pragma once
#ifndef AXLE_H
#define AXLE_H
#include "part.h"
class Axle : public Part {
public:
	Axle(string mat = "45�ֵ���",string hard = "200HBS"):Part(mat,hard){
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
	//�����Ϣ����
	void setInfo(std::ostream& os);		

	double d;					//���ֱ��
	double Iz;					//���Ծ�
	double len;					//��ĳ���
	double O;					//��ѹǿ��
	double t;					//����ǿ��
};
#endif