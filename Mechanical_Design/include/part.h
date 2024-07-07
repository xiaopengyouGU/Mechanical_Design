
#ifndef PART_H
#define PART_H
#include<string>
#include<iostream>

using std::string;
using std::ostream;
class Part {
public:
	Part(string mat,string hard):Material(mat),Hardness(hard){}
	virtual ~Part() {};		//���麯����ʵ�ֳ������
	string getMaterial() const {
		return Material;
	}
	virtual void showInfo(ostream& os) = 0;		//��ʾ�����Ϣ
protected:
	string Material;	//����
	string Hardness;	//Ӳ��
	int Level = 7;		//����ľ��ȵȼ�
};
#endif // !PART_H