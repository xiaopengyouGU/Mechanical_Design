#pragma once
#ifndef BEARING_DESIGN_H
#define BEARING_DESIGN_H
#include "part_design.h"
#include "bearing.h"
class Bearing_Design : public Part_Design {
public:
	Bearing_Design(string load = "���غ�") :Part_Design(load) {}
	Bearing_Design(bool b, shared_ptr<Bearing> p = nullptr, string load = "���غ�")
		:Part_Design(load), part(p) {
		setDesign(b);
	}
	~Bearing_Design() {};

	void setDesign(bool b) override;
	void showDesignInfo(ostream& os) override;	//ֱ�����ظú���

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

	void testC(ostream&os);						//���㵱�����غ�
	void setXandY();							//�ò�ֵ��ȷ��X��Y,ֻ֧��70000AC��������
	void setUserChoice(ostream&os);
	void setDefault() override;					//Ĭ�ϲ���
	void setBasicParameter(ostream& os);		//Ĭ�ϲ����趨
	void setBearingParameter(ostream& os);		//��в����趨

	shared_ptr<Bearing> part;					//�������һ��ֻ���һ�����
	double Fr = 5500;							//������
	double Fa = 2700;							//������
	double X = 1;								//�����غ�ϵ��
	double Y = 0;								//�����غ�ϵ��
	double P = 0;								//�������غ�
	double Cd = 61800;							//��������غ�,25.5KN
	double Co = 38000;							//��������غ�
	double fd = 1.2;							//����ϵ��
	double ft = 1.0;							//�¶�ϵ����Ĭ��Ϊ1.00, 120������
	double Lh = 5000;							//������� 1x10^6Ϊ����
	double c = 3;								//ָ�� L = (C/P)^c
	double e = 0.44;							//�ж�ϵ��
	double n = 1250;							//��е�ת��

};
#endif