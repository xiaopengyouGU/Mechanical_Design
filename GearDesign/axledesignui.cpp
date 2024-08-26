#include "axledesignui.h"
#include "ui_axledesignui.h"
#include <QMessageBox>
AxleDesignUI::AxleDesignUI(QWidget *parent)
    : DesignUI(parent)
    , ui(new Ui::AxleDesignUI)
{
    ui->setupUi(this);
}

AxleDesignUI::~AxleDesignUI()
{
    delete ui;
}

void AxleDesignUI::startDesign(DesignInfo *info)
{
    m_info = info;  //修改设计信息指针
}

void AxleDesignUI::on_btnMat_clicked()
{
    QPixmap pic(":/images/images/Axle_Mat.png");
    ui->labPic->setPixmap(pic);
}


void AxleDesignUI::on_btn_a_clicked()
{
    QPixmap pic(":/images/images/Axle_Test.png");
    ui->labPic->setPixmap(pic);
}


void AxleDesignUI::on_btnAo_clicked()
{
    QPixmap pic(":/images/images/Axle_t.png");
    ui->labPic->setPixmap(pic);
}


void AxleDesignUI::on_btnCalcT_clicked()
{
    double n = ui->spin_n->value(),P = ui->spin_P->value();
    double T = 9550000*P/n;
    ui->spin_T->setValue(T);
}


void AxleDesignUI::on_btnW_clicked()
{
    double d = ui->spin_d->value();
    double W = M_PI*pow(d,3)/32;
    ui->spinW->setValue(W);
}


void AxleDesignUI::on_btnChart_clicked()
{
    QPixmap pic(":/images/images/Axle_Chart.png");
    ui->labPic->setPixmap(pic);
}


void AxleDesignUI::on_btnTestT_clicked()
{
    QPixmap pic(":/images/images/Axle_TT.png");
    ui->labPic->setPixmap(pic);
}


void AxleDesignUI::on_btnNote_clicked()
{
    QPixmap pic(":/images/images/Axle_note.png");
    ui->labPic->setPixmap(pic);
}


void AxleDesignUI::on_btnOF_clicked()
{
    on_btnMat_clicked();
}

void AxleDesignUI::reFresh()
{
    m_info->clearInfo();
    ui->textEdit->clear();
    on_btnAo_clicked();
    state = false;
}


void AxleDesignUI::on_actStart_triggered()
{
    m_info = new DesignInfo(this);
    reFresh();
    calcOF();         //校核轴的强度
}


void AxleDesignUI::on_actShow_triggered()
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

void AxleDesignUI::calcOF()
{//计算轴的强度
    double n = ui->spin_n->value(),P = ui->spin_P->value();
    double Ao = ui->spinAo->value();
    double d = ui->spin_d->value();       //最小直径
    on_btnW_clicked();                    //获取抗扭截面系数
    on_btnCalcT_clicked();
    double T = ui->spin_T->value(),M = ui->spinM->value();
    double a = ui->spin_a->value();     //脉动循环，取0.6
    double W = ui->spinW->value(),OF = ui->spinOF->value();
    double tmpOF = sqrt(M*M+(a*T)*(a*T))/W;    //获取最终的弯曲应力
    double tmpD = pow(32*sqrt(M*M+(a*T)*(a*T))/(M_PI*OF),1.0/3); //所需的最小直径
    if(tmpOF < OF){
        //保存设计信息
        QMessageBox::information(this,"信息","轴的设计完毕,输出设计信息");
        //保存设计信息
        QString str = "***轴的设计***\n";
        str = str + "设计条件:\n";
        str = str + QString::asprintf("转速n = %.2f r/min\n",n);
        str = str + QString::asprintf("传递的功率P = %.1f KW \n",P);
        str = str + QString::asprintf("危险截面处弯矩M= %.0f N*mm\n",M);
        str = str + "**********************\n";
        str = str + "轴的材料：" + ui->editMat->text() + "\n";
        str = str + QString::asprintf("Ao = %.1f \n",Ao);
        str = str + QString::asprintf("轴的直径d = %.0f mm\n",d);
        str = str + QString::asprintf("抗扭截面系数W = %.1f mm^3\n",W);
        str = str + QString::asprintf("最大弯曲应力OF = %.1f Mpa\n",tmpOF);
        str = str + "**********************\n";
        m_info->appendInfo(str);
        m_info->setInfo(str);
        //其他参数获取,用于设计库显示
        m_info->setType("轴的设计");
        m_info->setLevel(7);
        m_info->setMaterial(ui->editMat->text());
        ui->textEdit->appendPlainText(str);
        state = true;           //更新设计状态
    }
    else{
        QMessageBox::warning(this,"警告","轴的强度不够");
        QString str = "***轴的强度校核***\n";
        str = str + "**********************\n";
        str = str + QString::asprintf("当前最大弯曲应力OF = %.2f Mpa\n",tmpOF);
        str = str + QString::asprintf("许用弯曲应力[OF] = %.0f Mpa\n",OF);
        str = str + QString::asprintf("所需的最小直径d = %.1f mm\n",tmpD);
        str = str + "**********************\n";
        ui->textEdit->appendPlainText(str);
    }

}


void AxleDesignUI::on_btnKA_clicked()
{
    QPixmap pic(":/images/images/Axle_KA.png");
    ui->labPic->setPixmap(pic);
}


void AxleDesignUI::on_btn_d_clicked()
{
    double Ao = ui->spinAo->value();
    double P = ui->spin_P->value(),n = ui->spin_n->value();
    double d = Ao*pow(P/n,1.0/3);       //最小直径
    ui->spin_d->setValue(d);
}

