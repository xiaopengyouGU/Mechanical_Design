#ifndef MECHANICALDESIGN_H
#define MECHANICALDESIGN_H
#include<QSqlDatabase>
#include<QItemSelectionModel>
#include <QSqlTableModel>
#include <QMainWindow>
#include<QDataWidgetMapper>
#include<QSqlRecord>
#include <QRandomGenerator>
#include "designvec.h"
namespace Ui {
class MechanicalDesign;
}

class MechanicalDesign : public QMainWindow
{
    Q_OBJECT
private:
    DesignVec* m_Vec;           //设计表类
    QSqlDatabase DB;            //数据库连接
    QSqlTableModel *tabModel = nullptr;   //数据模型,考虑到用户可能没有打开数据库
    QItemSelectionModel *selModel;  //选择模型
    QDataWidgetMapper *dataMapper;  //数据映射
    //状态栏标签
    QLabel * labDate;               //设计日期
    QLabel* labCount;               //设计数量
    QLabel* labInfo;                //设计说明
    //区别开历史设计和本次设计
    int base = 0;                  //历史设计的数量
public:
    explicit MechanicalDesign(QWidget *parent = nullptr);
    ~MechanicalDesign();

private slots:
    void do_addDesign(int index);   //往数据库中添加一个设计
    void on_actGear_triggered();

    void on_actKey_triggered();

    void on_actAxle_triggered();

    void on_actBearing_triggered();

    void on_btnDeleteAll_clicked();

    void on_actOutput_triggered();
    void on_actOpenDB_triggered();

    void on_btnDelete_clicked();

    void on_actSave_triggered();

    void on_radioGear_clicked();

    void on_radioKey_clicked();

    void on_radioBearing_clicked();

    void on_radioAxle_clicked();

    void on_radioAll_clicked();

    void on_chkSort_clicked(bool checked);

private:
    void OpenTable();               //打开数据表
    void do_currentRowChanged(const QModelIndex&current, const QModelIndex& previous);
    void showRecordCount();           //显示设计数量
private:
    Ui::MechanicalDesign *ui;
};

#endif // MECHANICALDESIGN_H
