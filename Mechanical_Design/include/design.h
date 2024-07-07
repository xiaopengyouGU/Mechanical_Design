#pragma once
#ifndef DESIGN_H
#define DESIGN_H
#include<memory>
#include<cmath>
#include<ctime>
#include<iostream>
#include"part.h"
using std::shared_ptr;  //ʹ������ָ�룬���ö�̬��
using std::iostream;
class Design {
public:
	Design()noexcept{}
	virtual ~Design() = 0;
protected:
	time_t timer = 0;
	virtual void showDesignInfo(ostream& os) noexcept{};
};
#endif