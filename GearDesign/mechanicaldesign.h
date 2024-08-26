#ifndef MECHANICALDESIGN_H
#define MECHANICALDESIGN_H

#include <QMainWindow>
#include "designvec.h"
namespace Ui {
class MechanicalDesign;
}

class MechanicalDesign : public QMainWindow
{
    Q_OBJECT
private:
    DesignVec* m_Vec;           //设计表类
public:
    explicit MechanicalDesign(QWidget *parent = nullptr);
    ~MechanicalDesign();

private:
    Ui::MechanicalDesign *ui;
};

#endif // MECHANICALDESIGN_H
