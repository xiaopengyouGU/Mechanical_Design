#pragma once
#ifndef DESIGN_VEC_H
#define DESIGN_VEC_H
#include <vector>
//�������еľ��������
#include "spur_gear_drive.h"
#include "bevel_gear_drive.h"
#include "key_design.h"
#include "bearing_design.h"
#include "axle_design.h"
//#define USER_CHOICE		//�����û��ֶ�����
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
	//ע�����������Ʋ���ʱ��������ostream& ���͵��β�
	//�����������ƽ����ӡ���ļ���
	void addDesign(int type,std::ostream&os = std::cout);			//���һ����ƶ���
	void deleteDesign(int pos,std::ostream&os = std::cout);			//ɾ��һ����ƶ���
	void showDesign(int pos,std::ostream&os = std::cout);			//��ʾһ����ƶ���
	void showTotalDesign(bool b,std::ostream&os = std::cout);		//��ʾ������ƶ�����ϸ���
	void deleteTotalDesign(std::ostream&os = std::cout);						//ɾ��������ƶ���

	enum DesignVector { SpurGearDrive, BevelGearDrive, BeltDrive,ChainDrive,KeyDesign, AxleDesign,
		DeepBearingDesign,AngleBearingDesign };
	//����ö��ֵ�������������������
private:
	std::vector<shared_ptr<Design>> VecPtr;			//ʹ�ð�������ָ�������
	
};

#endif
