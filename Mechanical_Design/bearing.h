#pragma once
#ifndef BEARING_H
#define BEARING_H
#include "part.h"
//��г������
class Bearing : public Part {
public:
	Bearing(string mat = "��и�", string hard = "60HRC"):Part(mat,hard){}
	~Bearing() {};

	//void showInfo(ostream& os) override;		//����

	string getCode()const { return code; }
	string gettype()const { return type; }
	int getd() const { return d; }

	void setInfo(ostream& os);					//ȷ���ھ�������
	void setd(int val) { d = val; }							//ȷ���ھ�
	void setCode(string str) { code = str; }
	void settype(string str) { type = str; }
protected:
	string code  = "10";						//�ھ�����
	string type = "������";					//����ͺ�
	int d = 50;									//�ھ�
};

class Deep_Bearing : public Bearing {
public:
	Deep_Bearing(string mat = "��и�", string hard = "60HRC") :Bearing(mat, hard) {}
	~Deep_Bearing() {};

	void showInfo(ostream& os) override;		//����
};

class Angle_Bearing : public Bearing {
public:
	Angle_Bearing(string mat = "��и�", string hard = "60HRC") :Bearing(mat, hard) {
		type = "�ǽӴ������AC";
	}
	~Angle_Bearing() {};

	void showInfo(ostream& os) override;		//����
};
#endif