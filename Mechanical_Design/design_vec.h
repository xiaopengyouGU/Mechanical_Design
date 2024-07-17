#pragma once
#ifndef DESIGN_VEC_H
#define DESIGN_VEC_H
#include <vector>
//�������еľ��������
#include "spur_gear_drive.h"
#include "bevel_gear_drive.h"

class Design_Vec {
public:
	Design_Vec() = default;	//Ĭ�Ϲ��캯��
	Design_Vec(const std::vector<shared_ptr<Design>> &vec):VecPtr(vec){}
	Design_Vec(const Design_Vec& rhs):VecPtr(rhs.VecPtr){}
	Design_Vec& operator=(const Design_Vec& rhs) {	//���ظ�ֵ�����
		VecPtr = rhs.VecPtr;
		return *this;
	}
	~Design_Vec() { std::cout << "����������!" << std::endl;}

	int getSize()const { return VecPtr.size(); }	//������ƶ�����Ŀ

	void addDesign(shared_ptr<Design> des);			//���һ����ƶ���
	void deleteDesign(int pos);						//ɾ��һ����ƶ���
	void showDesign(int pos);						//��ʾһ����ƶ���
	void showTotalDesign(bool b);					//��ʾ������ƶ�����ϸ���
	void deleteTotalDesign();						//ɾ��������ƶ���
	
private:
	std::vector<shared_ptr<Design>> VecPtr;			//ʹ�ð�������ָ�������
};

#endif
