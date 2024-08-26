#ifndef KEYDESIGNUI_H
#define KEYDESIGNUI_H

#include <QMainWindow>
#include "designinfo.h"
namespace Ui {
class KeyDesignUI;
}

class KeyDesignUI : public QMainWindow
{
    Q_OBJECT
private:
    DesignInfo* m_info;     //设计类
    bool state = false;             //设计状态
public:
    explicit KeyDesignUI(QWidget *parent = nullptr);
    void startDesign(DesignInfo* info);
    ~KeyDesignUI();
private:
    void calcObs();     //校核挤压强度
    void reFresh();     //刷新UI界面
private slots:
    void on_btn_b_clicked();

    void on_btn_h_clicked();

    void on_btn_d_clicked();

    void on_btn_L_clicked();

    void on_btnCalcT_clicked();

    void on_btn_FlowerO_clicked();

    void on_btn_calFlower_clicked();

    void on_btn_FatPara_clicked();

    void on_btn_calFat_clicked();

    void on_btnObs_clicked();

    void on_btnLoad_clicked();

    void on_actStart_triggered();

    void on_actClear_triggered();

    void on_actShow_triggered();

private:
    Ui::KeyDesignUI *ui;
};

#endif // KEYDESIGNUI_H
