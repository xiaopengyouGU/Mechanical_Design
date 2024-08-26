#ifndef GEARDESIGNUI_H
#define GEARDESIGNUI_H

#include <QMainWindow>
#include<QtMath>
#include<QMessageBox>
#include "designinfo.h"
#define M_PI       3.14159265358979323846				//定义Pi
#define HA      1 //齿顶高系数
#define CA       0.25//顶隙系数
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class GearDesignUI : public DesignUI
{
    Q_OBJECT
private:
    //DesignInfo* m_info = nullptr;       //设计信息
    bool c_state = false;       //接触设计状态:等待输入与否
    bool b_state = false;       //弯曲设计状态:等待输入与否
    double m_dt  = 0;            //设计分度圆半径
    double m_mt = 0;             //设计模数
public:
    void startDesign(DesignInfo* info);     //唯一的公共接口
    GearDesignUI(QWidget *parent = nullptr);
    ~GearDesignUI();
private slots:
    void on_btnKHV_clicked();

    void on_btnKA_clicked();

    void on_btn_q_clicked();

    void on_btnKHN_clicked();

    void on_btnKFN_clicked();

    void on_btnKFa_clicked();

    void on_btnKHa_clicked();

    void on_btnKHb_clicked();

    void on_btnKFb_clicked();

    void on_btnKFV_clicked();

    void on_btnGetT_clicked();

    void on_actContinue_triggered();

    void on_btnYFa_clicked();

    void on_btnYSa_clicked();

    void on_actStart_triggered();

    void on_btnBigMat_clicked();

    void on_btnSmallMat_clicked();

    void on_btnLevel_clicked();

    void on_btnBigOF_clicked();

    void on_btnSmallOF_clicked();

    void on_btnBigOH_clicked();

    void on_btnSmallOH_clicked();

    void on_btn_m_clicked();

    void on_btn_a_clicked();        //结束最终设计的函数

    void on_actShowAll_triggered();

    void on_actShow_triggered();

private:
    void Contact_Fatigue_Design();  //接触疲劳强度
    void Bend_Fatigue_Design();     //弯曲疲劳强度
    void calcDiameter();            //试算分度圆半径
    void searchChartForContact();    //接触查表
    void calcFinalDiameter();        //计算最终的分度圆半径
    void calcModulus();             //试算模数
    void searchChartForBend();      //弯曲查表
    void calcFinalModulus();        //计算最终的模数
    //8个主要计算函数
    void reFresh();                         //刷新UI界面
    void calcKN();      //计算应力循环次数
    double Angle_to_Radian(double angle) {return angle*M_PI/180;} //角度转弧度
    double Radian_to_Angle(double radian) {return radian*180/M_PI;} //弧度转角度
private:
    Ui::MainWindow *ui;     //这个对象不要改
};

#endif // GEARDESIGNUI_H
