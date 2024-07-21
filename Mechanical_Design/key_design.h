#pragma once
#ifndef KEY_DESIGN_H
#define KEY_DESIGN_H
#include "part_design.h"
#include "key.h"
//�������
class Key_Design : public Part_Design {
public:
	Key_Design(bool b = true, string load = "���غ�") :Part_Design(load) {
		setDesign(b);							//��ʼ���
	}
	~Key_Design() {};
	void showDesignInfo(ostream& os) override;	//
	void setDesign(bool b) override;			//����
private:
	void setDefault() override;
	void setUserChoice(ostream&os) override;	//�û��ֶ�����
	void testStrength(ostream& os) ;			//ǿ��У��
	void setKeybandh(ostream&os);				//ȷ�����Ŀ�Ⱥ͸߶�,������ĳ��ȷ�Χ
	void showPossibleL(ostream& os);			//������ĳ���ϵ��

	void setp(double val) { p = val; }
	void setbs(double val) { bs = val;}
	void setT(double val) { T = val; }
	void setb(double val) { b = val; }
	void setd(double val) { d = val; }

	shared_ptr<Key> part;						//�������
	double p;									//����Ӧ��,������ʱ����
	double bs = 110;							//���ü�ѹӦ��,Ĭ�Ͼ����ӣ����챶��Ǹ�
	double T = 2200;							//�봫�ݵ�ת�� N m
	double b = 100;								//��챵Ŀ��
	double d = 70;								//���ֱ��
};

#endif