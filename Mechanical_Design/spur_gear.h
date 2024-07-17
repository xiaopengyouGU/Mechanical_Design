#ifndef SPUR_GEAR_H
#define SPUR_GEAR_H
#include "gear.h"
class Spur_Gear : public Gear {
public:
	Spur_Gear(string mat, string hard):Gear(mat,hard){
		std::cout << "��ֱ���ֵĲ����ǣ�" << mat << " " << "Ӳ���ǣ�" << hard <<std::endl;
		std::cout << "����������Ӵ�ƣ��ǿ�ȣ�����ƣ��ǿ�ȣ�����" << std::endl;
		double tmpoh, tmpof, tmpz;
		std::cin >> tmpoh >> tmpof >> tmpz;
		OH = tmpoh, OF = tmpof;
		Z = tmpz;
	}
	Spur_Gear(string mat, string hard, double oh, double of, int z1, double P = 0)
		:Gear(mat, hard, oh, of,z1,P) {}
	~Spur_Gear();

	void showInfo(ostream& os) override;	//����ֻ������Part��showInfo

};

#endif 
