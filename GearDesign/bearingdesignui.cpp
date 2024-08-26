#include "bearingdesignui.h"
#include "ui_bearingdesignui.h"
#include <QMessageBox>
BearingDesignUI::BearingDesignUI(QWidget *parent)
    : DesignUI(parent)
    , ui(new Ui::BearingDesignUI)
{
    ui->setupUi(this);
    this->resize(700,500);
}

BearingDesignUI::~BearingDesignUI()
{
    delete ui;
}

void BearingDesignUI::startDesign(DesignInfo *info)
{
    m_info = info;
}

void BearingDesignUI::on_btnLife_clicked()
{
    QPixmap pic(":/images/images/Bearing_Lh.png");
    ui->labPic->setPixmap(pic);
}


void BearingDesignUI::on_btn_e_clicked()
{
    QPixmap pic(":/images/images/Bearing_XY.png");
    ui->labPic->setPixmap(pic);
}


void BearingDesignUI::on_btnX_clicked()
{
    on_btn_e_clicked();
}


void BearingDesignUI::on_btnY_clicked()
{
    on_btn_e_clicked();
}


void BearingDesignUI::on_btn_f_clicked()
{
    QPixmap pic(":/images/images/Bearing_f.png");
    ui->labPic->setPixmap(pic);
}


void BearingDesignUI::on_btnFd_clicked()
{
    QPixmap pic(":/images/images/Bearing_Fd.png");
    ui->labPic->setPixmap(pic);
}

void BearingDesignUI::calcLife()
{//获取必要参数
    double Fr = ui->spinFr->value(),Fa = ui->spinFa->value();
    double fd = ui->spin_f->value();
    double v = 3;           //指数，球轴承v = 3,滚子轴承v = 10/3
    double X = ui->spinX->value(), Y = ui->spinY->value();
    double d = ui->spin_d->value();
    //计算当量动载荷
    double P = fd*(X*Fr + Y*Fa);
    //计算轴承寿命
    double n = ui->spin_n->value(),Lh = ui->spinLife->value();
    double tC = ui->spinC->value()*1000,Co = ui->spinCo->value();
    int curIndex = ui->comboBearing->currentIndex();
    if(curIndex == 1 || curIndex == 2 || curIndex == 7){
        v = 10/3;           //如果是滚子轴承
    }
    double tmpLh = 1000000.0*pow(tC/P,v)/(60*n);       //计算出的寿命
    double tmpC = pow(Lh*60*n/1000000.0,1/v)*P;               //所需的当量动载荷
    if(tmpLh > Lh){
        //保存设计信息
        QMessageBox::information(this,"信息","轴承的设计完毕,输出设计信息");
        //保存设计信息
        QString str = "***轴承的设计***\n";
        str = str + "设计条件:\n";
        str = str + QString::asprintf("径向载荷Fr = %.1f N \n",Fr);
        str = str + QString::asprintf("轴向载荷Fa = %.1f N \n",Fa);
        str = str + QString::asprintf("轴承内径d = %.0f mm\n",d);
        str = str + QString::asprintf("载荷系数fd = %.1f \n",fd);
        str = str + QString::asprintf("预期寿命Lh = %.0f h\n",Lh);
        str = str + QString::asprintf("轴承转速n = %.2f r/min \n",n);
        str = str + "**********************\n";
        str = str + "轴承类型：" + ui->comboBearing->currentText() + "\n";
        str = str + QString::asprintf("基本额定动载荷C = %.1f KN\n",tC/1000);
        str = str + QString::asprintf("基本额定静载荷Co = %.1f KN\n",Co);
        str = str + QString::asprintf("实际寿命 = %.1f h\n",tmpLh);
        str = str + "**********************\n";
        m_info->appendInfo(str);
        m_info->setInfo(str);
        //其他参数获取,用于设计库显示
        m_info->setType("轴承的设计");
        m_info->setLevel(7);
        m_info->setMaterial("轴承钢");
        ui->textEdit->appendPlainText(str);
        state = true;           //更新设计状态
    }
    else{
        QMessageBox::warning(this,"警告","轴承的寿命不够\n请更改轴承型号");
        QString str = "***轴承的寿命校核***\n";
        str = str + "**********************\n";
        str = str + QString::asprintf("当前寿命 = %.1f h\n",tmpLh);
        str = str + QString::asprintf("预期寿命 = %.0f h\n",Lh);
        str = str + QString::asprintf("对应的基本额定动载荷C = %.1f KN\n",tmpC/1000);
        str = str + "**********************\n";
        ui->textEdit->appendPlainText(str);
    }

}

void BearingDesignUI::reFresh()
{
    m_info->clearInfo();
    ui->textEdit->clear();
    on_btnLife_clicked();
    state = false;
}


void BearingDesignUI::on_actStart_triggered()
{
    m_info = new DesignInfo(this);
    reFresh();
    calcLife();         //校核轴承寿命
}


void BearingDesignUI::on_actShow_triggered()
{
    if(m_info == nullptr){
        QMessageBox::warning(this,"警告","请先点击'开始设计按钮'");
    }
    else{
        if(state){
            ui->textEdit->clear();
            ui->textEdit->appendPlainText(m_info->info());
        }
        else{
            QMessageBox::warning(this,"警告","请先点击'开始设计按钮'");
        }
    }
}

