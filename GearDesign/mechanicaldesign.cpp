#include "mechanicaldesign.h"
#include "ui_mechanicaldesign.h"

MechanicalDesign::MechanicalDesign(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MechanicalDesign)
{
    ui->setupUi(this);
    m_Vec = new DesignVec(this);        //创建设计表对象
}

MechanicalDesign::~MechanicalDesign()
{
    delete ui;
}
