#ifndef BEARINGDESIGNUI_H
#define BEARINGDESIGNUI_H

#include <QMainWindow>
#include "designinfo.h"
namespace Ui {
class BearingDesignUI;
}

class BearingDesignUI : public DesignUI
{
    Q_OBJECT
private:
    //DesignInfo* m_info;     //设计类
    bool state = false;     //设计状态
public:
    explicit BearingDesignUI(QWidget *parent = nullptr);
    ~BearingDesignUI();
    void startDesign(DesignInfo*info);

private slots:
    void on_btnLife_clicked();

    void on_btn_e_clicked();

    void on_btnX_clicked();

    void on_btnY_clicked();

    void on_btn_f_clicked();

    void on_btnFd_clicked();
    void on_actStart_triggered();

    void on_actShow_triggered();

private:
    void calcLife();        //计算轴承的寿命是否满足要求
    void reFresh();         //刷新UI
private:
    Ui::BearingDesignUI *ui;
};

#endif // BEARINGDESIGNUI_H
