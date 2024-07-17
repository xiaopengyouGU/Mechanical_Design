
#ifndef PART_H
#define PART_H
#include<string>
#include<iostream>

using std::string;
using std::ostream;
class Part {
public:
	Part(string mat,string hard):Material(mat),Hardness(hard){}
	virtual ~Part() {};									//虚函数
	virtual void showInfo(ostream& os) = 0;				//纯虚函数，输出零件具体信息

	string getMaterial() const { return Material; }		//获取材料
	string getHardness() const { return  Hardness; }	//获取硬度
	int getLevel() const { return Level; }				//获取精度等级

	void setMaterial(string str) { Material = str; }	//设置精度等级
	void setHardness(string str) { Hardness = str; }
	void setLevel(int val) { Level = val; }

protected:
	string Material;									//材料
	string Hardness;									//硬度
	int Level = 7;										//精度等级
};
#endif 