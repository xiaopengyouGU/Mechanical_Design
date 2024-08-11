#pragma once
#ifndef KEY_H
#define KEY_H
#include "part.h"
//����һ����,����Ϊ�������
class Key : public Part {
public:
	Key(string mat = "45��", string hard = "200HBS") : Part(mat, hard){}
	~Key() {};

	void showInfo(ostream& os) override;
	int getb() const { return b; }
	int geth() const { return h; }
	int getL() const { return L; }
	int getl()const { return l; }

	void setb(int val) { b = val; }
	void seth(int val) { h = val; }
	void setl(int val) { l = val; }
	void setL(int val) { L = val; }

protected:
	int b = 20;		//����
	int h = 12;		//����
	int L = 90;		//����
	int l = 70;		//���Ĺ�������
}
;

#endif