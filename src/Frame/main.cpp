#define _CRT_SECURE_NO_WARNINGS
#include "mechanical_design.h"
//利用宏编译,控制输出
//在design_vec.h中define USER_CHOICE开启用户手动操作
//在gear_drive.h中define SHOW_DETAIL显示每一步计算过程
//提供一个设计启动接口如下

int main(int argv, char *argc[])
{
    //注意如下格式
    Mechanical_Design();
}
