#include "keydesignui.h"
#include "ui_keydesignui.h"
#include <QMessageBox>
KeyDesignUI::KeyDesignUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KeyDesignUI)
{
    ui->setupUi(this);
    this->resize(800,450);
}

void KeyDesignUI::startDesign(DesignInfo *info)
{
    m_info = info;
}


KeyDesignUI::~KeyDesignUI()
{
    delete ui;
}

void KeyDesignUI::calcObs()
{//获取必要参数
    double T = ui->spin_T->value(),d = ui->spin_d->value();
    double b = ui->spin_b->value(),h = ui->spin_h->value();
    double L = ui->spin_L->value(), Obs = ui->spinObs->value();
    //进行强度校核
    double l = L - b;   //工作长度
    double tmpObs = 4000*T/(l*h*d);
    if(tmpObs > Obs){
        QMessageBox::warning(this,"警告","键的强度不够，会被压溃\n请修改尺寸");
        QString str = "***键的强度校核***\n";
        str = str + "**********************\n";
        str = str + QString::asprintf("当前挤压应力Obs = %.1f Mpa\n",tmpObs);
        str = str + QString::asprintf("许用挤压应力[Obs] = %.0f Mpa\n",Obs);
        str = str + "**********************\n";
        ui->textEdit->appendPlainText(str);
    }
    else{
        QMessageBox::information(this,"信息","键的设计完毕,输出设计信息");
        //保存设计信息
        QString str = "***键的设计***\n";
        str = str + "设计条件:\n";
        str = str + QString::asprintf("传递的转矩T = %.1f N*m \n",T);
        str = str + QString::asprintf("轴的直径d = %.0f mm\n",d);
        str = str + QString::asprintf("许用挤压应力[Obs] = %.0f Mpa\n",Obs);
        str = str + "**********************\n";
        str = str + QString::asprintf("键宽b= %.0f mm, 键高h = %.0f mm, 键长L = %.0f mm\n",b,h,L);
        str = str + "**********************\n";
        m_info->appendInfo(str);
        m_info->setInfo(str);
        //其他参数获取,用于设计库显示
        m_info->setType("键的设计");
        m_info->setLevel(7);
        m_info->setMaterial("45钢");
        ui->textEdit->appendPlainText(str);
        state = true;           //更新设计状态
    }
}

void KeyDesignUI::reFresh()
{
    m_info->clearInfo();
    ui->textEdit->clear();
    on_btn_b_clicked();
    state = false;
}

void KeyDesignUI::on_btn_b_clicked()
{
    QPixmap pic = QPixmap(":/images/images/Key_Size.png");
    ui->labPic->setPixmap(pic);
}


void KeyDesignUI::on_btn_h_clicked()
{
    on_btn_b_clicked();
}


void KeyDesignUI::on_btn_d_clicked()
{
    on_btn_b_clicked();
}


void KeyDesignUI::on_btn_L_clicked()
{
    on_btn_b_clicked();
}


void KeyDesignUI::on_btnCalcT_clicked()
{
    double n = ui->spin_n->value(), P = ui->spin_P->value();
    double T = 95500 * P/n; //计算转矩
    ui->spin_T->setValue(T);
}


void KeyDesignUI::on_btn_FlowerO_clicked()
{
    QPixmap pic = QPixmap(":/images/images/Key_Flower.png");
    ui->labPic->setPixmap(pic);
}


void KeyDesignUI::on_btn_calFlower_clicked()
{
    QPixmap pic = QPixmap(":/images/images/Key_calcFlower.png");
    ui->labPic->setPixmap(pic);
}


void KeyDesignUI::on_btn_FatPara_clicked()
{
    QPixmap pic = QPixmap(":/images/images/Key_Fat.png");
    ui->labPic->setPixmap(pic);
}


void KeyDesignUI::on_btn_calFat_clicked()
{
    QPixmap pic = QPixmap(":/images/images/Key_calFat.png");
    ui->labPic->setPixmap(pic);
}


void KeyDesignUI::on_btnObs_clicked()
{
    QPixmap pic = QPixmap(":/images/images/Key_Mat.png");
    ui->labPic->setPixmap(pic);
}


void KeyDesignUI::on_btnLoad_clicked()
{
    on_btnObs_clicked();
}


void KeyDesignUI::on_actStart_triggered()
{
    m_info = new DesignInfo(this);
    reFresh();  //刷新UI
    calcObs();  //校核强度
}


void KeyDesignUI::on_actClear_triggered()
{
    ui->textEdit->clear();
}


void KeyDesignUI::on_actShow_triggered()
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

