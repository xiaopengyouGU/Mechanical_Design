#pragma once
#ifndef ITERACTION_H
#define ITERACTION_H
//交互类-交换界面
#include<iostream>
class Iteraction {
public:
	Iteraction() { std::cout << "开始您的设计：" << std::endl;}
	~Iteraction() { std::cout << "再见！" << std::endl; }
	void setIni(std::ostream& os);	//设置初始化界面
	void setDriveDesign();	//具体的操作让Design_Vec类来实现
	void setPartDesign();	//零件设计
	char getch1() const { return ch1; }
	char getch2() const { return ch2; }
	char getch3() const { return ch3; }	//数据封装
private:
	char ch1;	//
	char ch2; //两个选项
	char ch3;
};

#endif // !ITERACTION_H
