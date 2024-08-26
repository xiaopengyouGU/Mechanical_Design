#ifndef AXLEDESIGNUI_H
#define AXLEDESIGNUI_H

#include <QMainWindow>
#include "designinfo.h"
namespace Ui {
class AxleDesignUI;
}

class AxleDesignUI : public DesignUI
{
    Q_OBJECT
private:
    //DesignInfo* m_info;     //设计类
    bool state = false;     //设计状态
public:
    explicit AxleDesignUI(QWidget *parent = nullptr);
    ~AxleDesignUI();
    void startDesign(DesignInfo*info);

private slots:
    void on_btnMat_clicked();

    void on_btn_a_clicked();

    void on_btnAo_clicked();

    void on_btnCalcT_clicked();

    void on_btnW_clicked();

    void on_btnChart_clicked();

    void on_btnTestT_clicked();

    void on_btnNote_clicked();

    void on_btnOF_clicked();
    void on_actStart_triggered();

    void on_actShow_triggered();

    void on_btnKA_clicked();

    void on_btn_d_clicked();

private:
    void calcOF();        //计算轴的强度是否满足要求
    void reFresh();       //刷新UI
private:
    Ui::AxleDesignUI *ui;
};

#endif // AXLEDESIGNUI_H
