
#ifndef BEVEL_GEAR_H
#define BEVEL_GEAR_H
#include"gear.h"

class Bevel_Gear : public Gear {
public:
	Bevel_Gear(string mat, string hard) :Gear(mat, hard) {
		std::cout << "�ó��ֵĲ����ǣ�" << mat << "Ӳ���ǣ�" << hard << std::endl;
		std::cout << "����������Ӵ�ƣ��ǿ�ȣ�����ƣ��ǿ�ȣ�������������" << std::endl;
		double tmpoh, tmpof, tmpz, tmpp;
		std::cin >> tmpoh >> tmpof >> tmpz >> tmpp;
		OH = tmpoh, OF = tmpof;
		Z = tmpz, p = tmpp;
	}
	Bevel_Gear(string mat, string hard,double oh,double of,int z1,double P = 14):
		Gear(mat,hard,oh,of,z1,P){}
	~Bevel_Gear();

	void showInfo(ostream& os) override;	//����б���ֵ�showInfo

	double getRotAngle() const noexcept{ return p; }
	double getat() const { return at; }		
	double getpb() const { return pb; }
	double getan() const { return an; }

	void setat(double val) { at = val; }
	void setpb(double val) { pb = val; }
	void setan(double val) { an = val; }
private:
	double at = 20;							//����ѹ����
	double an = 20;							//����ѹ���� tan(an) = tan(at)*cos(p)
	double pb = 20;							//��Բ������ tan(pb) = tan(p)*cos(at)
};

#endif
