#pragma once
#ifndef ITERACTION_H
#define ITERACTION_H
//交互类-交换界面
#include<iostream>
class Interaction {
public:
	Interaction() {}								
	~Interaction() {}

	void setIni(std::ostream& os);					//设置初始化界面
	void InteractionOfTotal(std::ostream& os);		//总设计界面的交互
	void InteractionOfDriveDesign(std::ostream& os);//传动设计界面的交互
	void InteractionOfPartDesign(std::ostream& os);	//零件设计界面的交互
	void InteractionOfGearDrive(std::ostream& os);	//齿轮传动设计界面
	void InteractionOfKey(std::ostream& os);		//键设计界面
	void InteractionOfAxle(std::ostream& os);		//轴设计界面
	void InteractionOfBearing(std::ostream& os);	//轴承的强度设计
	void InteractionOfChainDrive(std::ostream& os);	//链传动
	void InteractionOfBeltDrive(std::ostream& os);	//带传动
	void InteractionOfInfo(std::ostream& os);		//显示设计信息
	//其他部分的设计界面...
	char getGearDrive() const { return chGearDrive; }
	char getAxle() const { return chAxle; }
	char getTotal() const { return chTotal; }
	char getDrive() const { return chDrive; }
	char getPart() const { return chPart; }			
	char getShow()const { return chShow; }
	char getBearing()const { return chBearing; }

	void setTotal(char ch) { chTotal = ch;}			
	void setDrive(char ch) { chDrive = ch; }
	void setPart(char ch) { chPart = ch; }
	void setGearDrive(char ch) { chGearDrive = ch; }
	void setKey(char ch) { chKey = ch; }
	void setShow(char ch) { chShow = ch; }
	void setBearing(char ch) { chBearing = ch; }

private:
	char chTotal;									//总体选项
	char chDrive;									//传动选项
	char chPart;									//零件选项
	char chGearDrive;								//齿轮传动
	char chKey;										//键的设计
	char chAxle;									//轴的设计
	char chBearing;									//轴承的设计
	char chShow;									//设计信息
};

#endif
