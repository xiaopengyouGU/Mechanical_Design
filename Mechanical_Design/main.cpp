// Mechanical_Design.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
//#define GEAR_TEST
#include <iostream>
/*#include "spur_gear.h"
#include "bevel_gear.h"
#include "spur_gear_drive.h"
#include "bevel_gear_drive.h"*/

int main(int argv, char *argc[])
{
 //巧妙的利用宏编译
#ifdef GEAR_TEST
    //全部代码加起来不超过六百行
    Spur_Gear_Drive a(std::make_shared<Spur_Gear>("40Cr", "280HBW",600,500,24),
        std::make_shared<Spur_Gear>("45钢", "240HBW",550,320,77));
    //这里已经运用了动态绑定！因为内部是指针
    Bevel_Gear_Drive b(std::make_shared<Bevel_Gear>("40Cr", "280HBW",600,500,24,14),
        std::make_shared<Bevel_Gear>("45钢", "240HBW",550,320,77,14));
    std::cout << "Hello World!\n";*/
#endif // GEAR_TEST

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
