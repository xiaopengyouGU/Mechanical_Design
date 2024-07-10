#pragma once
#ifndef ITERACTION_H
#define ITERACTION_H
//交互类-交换界面
#include<iostream>
class Interaction {
public:
	Interaction() { }		//界面初始化
	~Interaction() { std::cout << "再见！" << std::endl; }
	void setIni(std::ostream& os);	//设置初始化界面
	void InterationOfTotal(std::ostream& os);		//总设计界面的交互
	void InterationOfDriveDesign(std::ostream& os);	//传动设计界面的交互
	void InterationOfPartDesign(std::ostream& os);	//零件设计界面的交互
	void InterationOfGearDrive(std::ostream& os);	//齿轮传动设计界面
	void InterationOfKey(std::ostream& os);			//键设计界面
	void InterationOfAxle(std::ostream& os);			//轴设计界面
	//其他部分的设计界面...
	void setTotal(char ch) { chTotal = ch;}		//利用接口操作
	void setDrive(char ch) { chDrive = ch; }
	void setPart(char ch) { chPart = ch; }
	void setGearDrive(char ch) { chGearDrive = ch; }
	void setKey(char ch) { chKey = ch; }
	char getGearDrive() const{ return chGearDrive; }

	char getAxle() const { return chAxle; }
	char getTotal() const { return chTotal; }
	char getDrive() const { return chDrive; }
	char getPart() const { return chPart; }	//数据封装
private:
	char chTotal;	//总体选项
	char chDrive; //传动选项
	char chPart;	//零件选项
	char chGearDrive;//齿轮传动
	char chKey;      //键的设计
	char chAxle;	//轴的设计
};

#endif // !ITERACTION_H
