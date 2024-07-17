// Mechanical_Design.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
//#define GEAR_TEST
#define DESIGN_TEST

#include <iostream>
#ifdef GEAR_TEST
#include "spur_gear.h"
#include "bevel_gear.h"
#include "spur_gear_drive.h"
#include "bevel_gear_drive.h"
#endif 

#ifdef DESIGN_TEST
#include "mechanical_design.h"
#endif

int main(int argv, char *argc[])
{
 //巧妙的利用宏编译
   
#ifdef GEAR_TEST
    //全部代码加起来约850行
   /*Spur_Gear_Drive a(true, std::make_shared<Spur_Gear>("40Cr", "280HBW", 600, 500, 24),
       std::make_shared<Spur_Gear>("45钢", "240HBW",550,320,77));
    //这里已经运用了动态绑定！因为内部是指针
    Bevel_Gear_Drive b(true,std::make_shared<Bevel_Gear>("40Cr", "280HBW",600,500,24,14),
        std::make_shared<Bevel_Gear>("45钢", "240HBW",550,320,77,14));*/
    //std::cout << "Hello World!\n";
    //Spur_Gear_Drive a(false, std::make_shared<Spur_Gear>("40Cr","280HBW",600,500, 24),
        //std::make_shared<Spur_Gear>("45钢", "240HBW",550,320,77));
    Bevel_Gear_Drive b(true, std::make_shared<Bevel_Gear>("40Cr", "280HBW"),
       std::make_shared<Bevel_Gear>("45钢", "240HBW"));
    //注意啊这里创建对象时先大齿轮，后小齿轮
 
#endif // GEAR_TEST
#ifdef DESIGN_TEST
    Mechanical_Design();    //测试Interaction类
#endif // 


}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
