#include "geardesignui.h"
#include "./ui_geardesignui.h"

void GearDesignUI::reFresh()
{   //刷新UI界面
    ui->btnKHa->setEnabled(false);
    ui->btnKHb->setEnabled(false);
    ui->btnKHV->setEnabled(false);
    ui->btn_m->setEnabled(false);
    ui->btnKFa->setEnabled(false);
    ui->btnKFb->setEnabled(false);
    ui->btnKFV->setEnabled(false);
    ui->btn_a->setEnabled(false);
    //
    ui->spinKHa->setEnabled(false);
    ui->spinKHb->setEnabled(false);
    ui->spinKHV->setEnabled(false);
    ui->spin_m->setEnabled(false);
    ui->spinKFa->setEnabled(false);
    ui->spinKFb->setEnabled(false);
    ui->spinKFV->setEnabled(false);
    ui->spin_a->setEnabled(false);
    //清空输出
    ui->textEdit->clear();
    ui->spinT->setValue(0);
    ui->labChart->setPixmap(QPixmap(":/images/images/KA.png"));
    c_state = false;
    b_state = false;
    m_info->clearInfo();


}

void GearDesignUI::startDesign(DesignInfo *info)
{
    m_info = info;
}

GearDesignUI::GearDesignUI(QWidget *parent)
    : DesignUI(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(950,700);

}

GearDesignUI::~GearDesignUI()
{
    delete ui;
}

void GearDesignUI::on_btnKHV_clicked()
{
    QPixmap pic(":/images/images/KV.png");
    ui->labChart->setPixmap(pic);
}


void GearDesignUI::on_btnKA_clicked()
{
    QPixmap pic(":/images/images/KA.png");
    ui->labChart->setPixmap(pic);
}


void GearDesignUI::on_btn_q_clicked()
{
    QPixmap pic(":/images/images/q.png");
    ui->labChart->setPixmap(pic);
}


void GearDesignUI::on_btnKHN_clicked()
{
    QPixmap pic(":/images/images/KHN.png");
    ui->labChart->setPixmap(pic);
    calcKN();           //计算应力循环次数
}


void GearDesignUI::on_btnKFN_clicked()
{
    QPixmap pic(":/images/images/KFN.png");
    ui->labChart->setPixmap(pic);
    calcKN();           //计算应力循环次数
}


void GearDesignUI::on_btnKFa_clicked()
{
    QPixmap pic(":/images/images/KHFa.png");
    ui->labChart->setPixmap(pic);
}


void GearDesignUI::on_btnKHa_clicked()
{
    QPixmap pic(":/images/images/KHFa.png");
    ui->labChart->setPixmap(pic);
}


void GearDesignUI::on_btnKHb_clicked()
{
    QPixmap pic(":/images/images/KHb.png");
    ui->labChart->setPixmap(pic);
}


void GearDesignUI::on_btnKFb_clicked()
{
    QPixmap pic(":/images/images/KFb.png");
    ui->labChart->setPixmap(pic);
}


void GearDesignUI::on_btnKFV_clicked()
{
    QPixmap pic(":/images/images/KV.png");
    ui->labChart->setPixmap(pic);
}


void GearDesignUI::on_btnGetT_clicked()
{
    double n = ui->spin_n->value();
    double P = ui->spinP->value();
    double T = 9550000 * P/n;
    ui->spinT->setValue(T);
}

void GearDesignUI::Contact_Fatigue_Design()
{
    calcDiameter();           //计算出试算分度圆直径和齿宽
    searchChartForContact();  //启动查表操作
    //calcFinalDiameter(dt);    //计算最终分度圆半径要等到用户按下“继续设计的按钮了”
}

void GearDesignUI::Bend_Fatigue_Design()
{//获取必要参数
    calcModulus();              //试算模数
    searchChartForBend();       //启动查表操作
}

void GearDesignUI::calcKN()
{   //计算应力循环次数
    double n = ui->spin_n->value(), time = ui->spinTime->value(); //转速和预期寿命
    double u = ui->spinU->value();  //传动比
    double N1 = n*time*60, N2 = N1/u;
    QString str = QString::asprintf("小齿轮的工作应力循环次数N1 = %e",N1);
    QString str1 = QString::asprintf("大齿轮的工作应力循环次数N2 = %e",N2);
    ui->textEdit->clear();
    ui->textEdit->appendPlainText("**************************");
    ui->textEdit->appendPlainText(str);
    ui->textEdit->appendPlainText(str1);
}

void GearDesignUI::calcDiameter()
{//试算分度圆半径
    int Z1 = ui->spinSmallZ->value(), Z2 = ui->spinBigZ->value();
    double OH1 = ui->spinSmallOH->value(),OH2 = ui->spinBigOH->value();
    double a = Angle_to_Radian(20), p = Angle_to_Radian(ui->spinSmallP->value());
    double q = ui->spin_q->value();
    //计算重合度：
    double at = atan(tan(a) / cos(p));          //小轮端面压力角
    double a1 = acos(Z1 * cos(at) / (Z1 + 2 * HA*cos(p)));  //小齿轮齿顶圆压力角
    double a2 = acos(Z2 * cos(at) / (Z2 + 2 * HA*cos(p)));  //大齿轮齿顶圆压力角
    double ea = (Z1 * (tan(a1) - tan(at)) + Z2 * (tan(a2) - tan(at))) / (2 * M_PI); //重合度ea
    double ep = q * Z1 * tan(p) / M_PI;             //轴向重合度
    double pb = atan(tan(p) * cos(at));             //基圆螺旋角
    //计算四个Z系数
    double ZH = sqrt(2 * cos(pb) / (cos(at) * sin(at)));  //区域系数
    double ZE = 189.8;                                    //弹性系数 Mpa^1/2
    double Ze = sqrt((4 - ea) / 3 * (1 - ep) + ep / ea);  //重合度系数
    double Zp = sqrt(cos(p));                        //螺旋角系数
    //计算疲劳强度极限
    double KHN1 = ui->spinKHN1->value(), KHN2 = ui->spinKHN2->value();
    double SH = ui->spinSH->value(),OH;
    OH1 = KHN1*OH1/SH, OH2 = KHN2*OH2/SH;
    OH = qMin(OH1,OH2);     //取小的
    //试算分度圆直径
    double Kt = ui->spinKt->value(), T = ui->spinT->value();
    double u = ui->spinU->value();
    double val1 = 2 * Kt * T / q;
    double val2 = (u + 1) / u;
    double val3 = (ZH * ZE * Ze *Zp / OH);
    val3 *= val3;						//取平方
    m_dt = pow(val1*val2*val3, 1.0 / 3);  //注意啊，要1.0！注意类型转换
    //将当前的这些设计信息保存到QString中
    QString info = "*****按接触强度设计*****\n\n";
    info = info + "***计算试算分度圆直径dt***\n";
    info = info + "******************************\n";
    info = info + "计算重合度：\n";
    info = info + QString::asprintf("小轮端面压力角at = %.3f 度\n",Radian_to_Angle(at));
    info = info + QString::asprintf("小齿轮齿顶圆压力角 = %.3f 度\n",Radian_to_Angle(a1));
    info = info + QString::asprintf("大齿轮齿顶圆压力角 = %.3f 度\n",Radian_to_Angle(a2));
    info = info + QString::asprintf("基圆螺旋角pb= %.3f 度\n",Radian_to_Angle(pb));
    info = info + QString::asprintf("重合度ea = %.3f \n",ea);
    info = info + QString::asprintf("轴向重合度ep = %.3f \n",ep);
    info = info + "计算四个Z系数：\n";
    info = info + QString::asprintf("区域系数ZH = %.3f \n",ZH);
    info = info + QString::asprintf("重合度系数Ze = %.3f \n",Ze);
    info = info + QString::asprintf("弹性系数ZE = %.1f Mpa^1/2\n",ZE);
    info = info + QString::asprintf("螺旋角系数Zp = %.3f \n",Zp);
    info = info + "计算疲劳强度极限：\n";
    info = info + QString::asprintf("小齿轮的接触疲劳极限OH1 = %.1f Mpa\n",OH1);
    info = info + QString::asprintf("大齿轮的接触疲劳极限OH2 = %.1f Mpa\n",OH2);
    info = info + QString::asprintf("取较小的一个，即[OH] = %.1f Mpa\n",OH);
    info = info + QString::asprintf("按照公式计算出试算分度圆直径dt = %.3f mm\n",m_dt);
    info = info + "********************************\n";
    m_info->appendInfo(info);      //保存信息到设计信息类中
    ui->textEdit->appendPlainText(info);//显示设计信息
}

void GearDesignUI::searchChartForContact()
{
    double b = m_dt*ui->spin_q->value(); //齿宽
    //查表获取接触齿间载荷分配系数
    double KA = ui->spinKA->value(),T = ui->spinT->value();
    double Ft = 2 * T / m_dt;
    double thre = KA * Ft / b;	//阈值
    QString str = "***开始查表操作*** \n";
    str = str + "**************************\n";
    str = str + QString::asprintf("径向力Ft = %.2f N\n",Ft);
    str = str + QString::asprintf( "KA*Ft/b = %.2f N/mm \n",thre);
    str += "************************";
    ui->textEdit->appendPlainText(str);
    //查表获取接触齿向载荷分配系数
    double q = ui->spin_q->value();
    str =  "小齿轮一般为非对称布置，硬齿面\n";
    str = str + QString::asprintf("小齿轮齿宽系数q = %.0f\n",q);
    str = str + QString::asprintf("齿宽b = %.3f mm\n",b);
    str += "************************";
    ui->textEdit->appendPlainText(str);
    //查表获取动载系数
    double n = ui->spin_n->value();
    double V = M_PI*n*m_dt/(60*1000);
    str = QString::asprintf("当前速度V = %.3f m/s\n",V);
    str = str+ "************************";
    ui->textEdit->appendPlainText(str);
    m_info->appendInfo(str);        //保存设计信息
    str = "点击按钮，获取接触齿间载荷分配系数KHa\n";
    str = str + "点击按钮，获取接触齿向载荷分配系数KFa\n";
    str = str + "点击按钮，获取接触动载系数KHV\n";
    str += "************************\n";
    ui->textEdit->appendPlainText(str);
    //使能按钮和spinBox
    ui->btnKHa->setEnabled(true);
    ui->btnKHb->setEnabled(true);
    ui->btnKHV->setEnabled(true);
    ui->spinKHa->setEnabled(true);
    ui->spinKHb->setEnabled(true);
    ui->spinKHV->setEnabled(true);
}

void GearDesignUI::calcFinalDiameter()
{
    double KA = ui->spinKA->value(),KV = ui->spinKHV->value();
    double Ka = ui->spinKHa->value(),Kb = ui->spinKHb->value();
    double K = KA*KV*Ka*Kb,Kt = ui->spinKt->value(); //实际工况系数和试算系数
    m_dt = m_dt * pow(K/Kt,1.0/3);      //最终得出的分度圆直径
    double Z1 = ui->spinSmallZ->value(),mt = m_dt/Z1;
    QString str = QString::asprintf("实际工况系数K = %.3f\n",K);
    str = str + QString::asprintf("最终得出的分度圆直径dt = %.3f mm\n",m_dt);
    str = str + QString::asprintf("对应的模数mt = %.3f mm\n",mt);
    str = str + "****************************\n";
    //ui->textEdit->appendPlainText(str + "*************************");
    //保存设计信息
    QString str1 = "***获取最终的分度圆直径***\n";
    str1 = str1 + "****************************\n";
    str1 = str1 + QString::asprintf("使用系数KA = %.2f\n",KA);
    str1 = str1 + QString::asprintf("接触动载系数KHV = %.2f\n",KV);
    str1 = str1 + QString::asprintf("接触齿间载荷分配系数KHa = %.3f\n",Ka);
    str1 = str1 + QString::asprintf("接触齿向载荷分配系数KHb = %.3f\n",Kb);
    str1 = str1 + str;
    //继续添加设计信息
    m_info->appendInfo(str1);
    ui->textEdit->appendPlainText(str1);
}

void GearDesignUI::calcModulus()
{
    int Z1 = ui->spinSmallZ->value(),Z2 = ui->spinBigZ->value();
    double p = ui->spinSmallP->value(),a = 20,c = 120;
    p = Angle_to_Radian(p), a = Angle_to_Radian(a),c = Angle_to_Radian(c);
    double q = ui->spin_q->value();
    //计算两个Y参数
    double at = atan(tan(a) / cos(p));
    double a1 = acos(Z1 * cos(at) / (Z1 + 2 * HA*cos(p)));
    double a2 = acos(Z2 * cos(at) / (Z2 + 2 * HA*cos(p)));
    double ea = (Z1 * (tan(a1) - tan(at)) + Z2 * (tan(a2) - tan(at))) / (2 * M_PI); //重合度ea
    double pb = atan(tan(p) * cos(at));
    double ep = q * Z1 * tan(p) / M_PI;
    double ev = ea / (cos(pb) * cos(pb));   //当量重合度
    double Ye = 0.25 + 0.75 / ev;           //弯曲重合度系数
    double Yp = 1 - ep * p / c;             //弯曲螺旋角系数
    //获取弯曲疲劳极限
    double OF1 = ui->spinSmallOF->value(), OF2 = ui->spinBigOF->value();
    double KFN1 = ui->spinKFN1->value(), KFN2 = ui->spinKFN2->value();
    double YFa1 = ui->spinYFa1->value(),YFa2 = ui->spinYFa2->value();
    double YSa1 = ui->spinYSa1->value(),YSa2 = ui->spinYSa2->value();
    double SF = ui->spinSF->value();
    OF1 = KFN1*OF1/SF,OF2 = KFN2*OF2/SF;
    //试算模数
    double T = ui->spinT->value(),Kt = ui->spinKt->value();
    double tmp1 = YFa1*YSa1/OF1, tmp2 = YFa2*YSa2/OF2;
    double val1 = qMax(tmp1,tmp2);      //取大的
    double val2 = (2 * Kt * T * Ye* Yp *cos(p)*cos(p)) / (q * Z1 * Z1);
    m_mt = pow(val2 * val1, 1.0 / 3);	//试算模数
    //保存设计参数
    QString info = "*****按弯曲强度设计*****\n\n";
    info = info + "***计算试算模数mt***\n";
    info = info + "******************************\n";
    info = info + "计算两个Y常数：\n";
    info = info + QString::asprintf("当量重合度ev = %.3f \n",ev);
    info = info + QString::asprintf("弯曲重合度系数Ye = %.3f \n",Ye);
    info = info + QString::asprintf("弯曲螺旋角系数Yp = %.3f \n",Yp);
    info = info + "计算弯曲疲劳强度：\n";
    info = info + QString::asprintf("小齿轮的弯曲疲劳极限OF1 = %.0f Mpa\n",OF1);
    info = info + QString::asprintf("大齿轮的弯曲疲劳极限OF2 = %.0f Mpa\n",OF2);
    info = info + QString::asprintf("YFa1*YSa1/OF1 = %.5f \n",tmp1);
    info = info + QString::asprintf("YFa2*YSa2/OF2 = %.5f \n",tmp2);
    info = info + QString::asprintf("取较大的一个，即 YFa*YSa/[OF] = %.5f \n",val1);
    info = info + QString::asprintf("按照公式计算出试算模数mt = %.3f mm\n",m_mt);
    info = info + "********************************\n";
    m_info->appendInfo(info);      //保存信息到设计信息类中
    ui->textEdit->appendPlainText(info);//显示设计信息

}

void GearDesignUI::searchChartForBend()
{//弯曲查表操作
    int Z1 = ui->spinSmallZ->value();
    double p = Angle_to_Radian(ui->spinSmallP->value());
    double dt = Z1 * m_mt/cos(p);      //获取分度圆半径
    double b = dt*ui->spin_q->value(); //齿宽
    //查表获取弯曲齿间载荷分配系数
    double KA = ui->spinKA->value(),T = ui->spinT->value();
    double Ft = 2 * T / dt;
    double thre = KA * Ft / b;	//阈值
    QString str = "***开始查表操作*** \n";
    str = str + "**************************\n";
    str = str + QString::asprintf("径向力Ft = %.2f N\n",Ft);
    str = str + QString::asprintf( "KA*Ft/b = %.2f N/mm \n",thre);
    str += "************************";
    ui->textEdit->appendPlainText(str);
    //查表获取弯曲齿向载荷分配系数
    double h = (2*HA + CA)*m_mt;     //齿高
    double tmp = b/h;               //宽高比
    double KHb = ui->spinKHb->value();
    str = QString::asprintf("接触齿向载荷分配系数KHb = %.3f\n",KHb);
    str = str + QString::asprintf("宽高比h/b = %.3f mm\n",tmp);
    str += "************************";
    ui->textEdit->appendPlainText(str);
    //查表获取动载系数
    double n = ui->spin_n->value();
    double V = M_PI*n*dt/(60*1000);
    str = QString::asprintf("当前速度V = %.3f m/s\n",V);
    str = str+ "************************";
    ui->textEdit->appendPlainText(str);
    m_info->appendInfo(str);        //保存设计信息
    str = "点击按钮，获取弯曲齿间载荷分配系数KHa\n";
    str = str + "点击按钮，获取弯曲齿向载荷分配系数KFa\n";
    str = str + "点击按钮，获取弯曲动载系数KHV\n";
    str += "************************\n";
    ui->textEdit->appendPlainText(str);
    //使能按钮和spinBox
    ui->btnKFa->setEnabled(true);
    ui->btnKFb->setEnabled(true);
    ui->btnKFV->setEnabled(true);
    ui->spinKFa->setEnabled(true);
    ui->spinKFb->setEnabled(true);
    ui->spinKFV->setEnabled(true);
}

void GearDesignUI::calcFinalModulus()
{//得出最终的模数
    double KA = ui->spinKA->value(),KV = ui->spinKFV->value();
    double Ka = ui->spinKFa->value(),Kb = ui->spinKFb->value();
    double K = KA*KV*Ka*Kb,Kt = ui->spinKt->value(); //实际工况系数和试算系数
    m_mt = m_mt * pow(K/Kt,1.0/3);      //最终得出的模数
    double p = Angle_to_Radian(ui->spinSmallP->value());//螺旋角
    double Z1 = ui->spinSmallZ->value();       //最终齿数
    double dt = m_mt*Z1/cos(p);                //对应的分度圆直径
    QString str = QString::asprintf("实际工况系数K = %.3f\n",K);
    str = str + QString::asprintf("最终得出的模数mt = %.3f mm\n",m_mt);
    str = str + QString::asprintf("对应的分度圆直径dt = %.3f mm\n",dt);
    str = str + "****************************\n";
    //ui->textEdit->appendPlainText(str + "*************************");
    //保存设计信息
    QString str1 = "***获取最终的模数***\n";
    str1 = str1 + "****************************\n";
    str1 = str1 + QString::asprintf("使用系数KA = %.2f\n",KA);
    str1 = str1 + QString::asprintf("弯曲动载系数KFV = %.2f\n",KV);
    str1 = str1 + QString::asprintf("弯曲齿间载荷分配系数KFa = %.3f\n",Ka);
    str1 = str1 + QString::asprintf("弯曲齿向载荷分配系数KFb = %.3f\n",Kb);
    str1 = str1 + str;
    //继续添加设计信息
    m_info->appendInfo(str1);
    str1 = str1 + "输入模数后，点击圆整模数按钮,可计算出中心距\n";
    str1 = str1 + "输入中心距后，点击圆整中心距按钮,可完成最终设计\n";
    ui->textEdit->appendPlainText(str1);
    //使能两个组件
    ui->btn_m->setEnabled(true);
    ui->spin_m->setEnabled(true);
    ui->spin_m->setValue(m_mt);
}



void GearDesignUI::on_actContinue_triggered()
{
    if(m_info == nullptr){
        QMessageBox::warning(this,"警告","请先点击‘开始设计’按钮");
        return;
    }
    if(!c_state){
        ui->textEdit->clear();      //清空输出
        calcFinalDiameter();
        c_state = true;
        Bend_Fatigue_Design();  //完成接触计算,开始弯曲计算
    }
    else{
        if(!b_state){
            ui->textEdit->clear();  //清空输出
            calcFinalModulus(); //计算最终的模数
            b_state = true;
        }
    }
}


void GearDesignUI::on_btnYFa_clicked()
{
    QPixmap pic(":/images/images/TwoY.png");
    ui->labChart->setPixmap(pic);
}


void GearDesignUI::on_btnYSa_clicked()
{
    on_btnYFa_clicked();
}


void GearDesignUI::on_actStart_triggered()
{
    m_info = new DesignInfo(this);    //创建信息变量
    reFresh();                        //重置UI界面
    on_btnGetT_clicked();             //计算力矩
    //分别按接触强度和弯曲强度设计
    Contact_Fatigue_Design();
    //Bend_Fatigue_Design();要等到按下“继续设计"后开始

}


void GearDesignUI::on_btnBigMat_clicked()
{
    QPixmap pic(":/images/images/Mat.png");
    ui->labChart->setPixmap(pic);
}


void GearDesignUI::on_btnSmallMat_clicked()
{
    on_btnBigMat_clicked();
}


void GearDesignUI::on_btnLevel_clicked()
{
    QPixmap pic(":/images/images/Level.png");
    ui->labChart->setPixmap(pic);
}


void GearDesignUI::on_btnBigOF_clicked()
{
    QPixmap pic(":/images/images/OF.png");
    ui->labChart->setPixmap(pic);
}


void GearDesignUI::on_btnSmallOF_clicked()
{
    on_btnBigOF_clicked();
}


void GearDesignUI::on_btnBigOH_clicked()
{
    QPixmap pic(":/images/images/OH.png");
    ui->labChart->setPixmap(pic);
}


void GearDesignUI::on_btnSmallOH_clicked()
{
    on_btnBigOH_clicked();
}


void GearDesignUI::on_btn_m_clicked()
{//开始计算中心距和齿数
    m_mt = ui->spin_m->value();
    double u = ui->spinU->value();
    double p = Angle_to_Radian(ui->spinSmallP->value());//螺旋角
    double Z1 = round(m_dt*cos(p)/m_mt);    //最终齿数
    double Z2 = round(Z1*u);                //大齿轮齿数
    //中心距
    double a = (Z1 + Z2)*m_mt / (2 * cos(p));
    //输出中心距
    QString info = "***********************\n";
    info = info + QString::asprintf("齿轮副的中心距a = %.2f mm\n",a);
    info = info + "***********************\n";
    //使能组件
    ui->spin_a->setValue(a);
    ui->spin_a->setEnabled(true);
    ui->btn_a->setEnabled(true);
}


void GearDesignUI::on_btn_a_clicked()
{//修正螺旋角
    double a = ui->spin_a->value();
    m_mt = ui->spin_m->value();
    double u = ui->spinU->value();
    double p = Angle_to_Radian(ui->spinSmallP->value());//螺旋角
    double Z1 = round(m_dt*cos(p)/m_mt);    //最终齿数
    double Z2 = round(Z1*u);                //大齿轮齿数
    p = acos((Z1 + Z2)*m_mt/(2*a));
    //计算齿轮分度圆直径
    double q = ui->spin_q->value();         //齿宽系数
    double d1 = Z1*m_mt/cos(p), d2 = Z2*m_mt/cos(p);
    double b2 = round(d1*q), b1 = b2 + 5;
    //保存主要设计信息
    double n = ui->spin_n->value(), P = ui->spinP->value();
    double KA = ui->spinKA->value(),time = ui->spinTime->value();
    QString info = "***主要设计信息***\n",str = ui->editSmallMat->text(),str1 = ui->editBigMat->text();
    info = info + "****************************\n";
    info = info + "设计条件：\n";
    info = info + QString::asprintf("小轮的转速n = %.2f r/min\n",n);
    info = info + QString::asprintf("小轮的传递的功率P = %.2f KW \n",P);
    info = info + QString::asprintf("预计工作时间time = %.0f h \n",time);
    info = info + QString::asprintf("使用系数KA = %.2f \n",KA);
    info = info + QString::asprintf("传动比u = %.2f \n",u);
    info = info + "****************************\n";
    info = info + QString::asprintf("小齿轮的齿数Z1 = %.0f \n",Z1);
    info = info + QString::asprintf("大齿轮的齿数Z2 = %.0f \n",Z2);
    info = info + QString::asprintf("模数mn = %.0f mm\n",m_mt);
    info = info + QString::asprintf("压力角A = 20 度 \n");
    info = info + QString::asprintf("中心距a = %.0f mm\n",a);
    info = info + QString::asprintf("螺旋角p = %.3f 度\n",Radian_to_Angle(p));
    info = info + QString::asprintf("小齿轮宽度b1 = %.0f mm, 分度圆直径d1 = %.3f mm\n",b1,d1);
    info = info + QString::asprintf("大齿轮宽度b2 = %.0f mm, 分度圆直径d2 = %.3f mm\n",b2,d2);
    info = info + "小齿轮采用"+str+ "\n";
    info = info + "大齿轮采用"+str1+ "\n";
    info = info + QString::asprintf("设计精度Level = %d\n",ui->spinLevel->value());
    info = info + "****************************\n";
    m_info->setInfo(info);
    m_info->appendInfo(info);
    //其他参数获取,用于设计库显示
    m_info->setType("齿轮设计");
    m_info->setLevel(ui->spinLevel->value());
    m_info->setMaterial("小齿轮采用"+str + "\t" + "大齿轮采用"+str1);
    //显示Message
    QMessageBox::information(this,"消息","设计结束,显示主要设计信息");
    ui->textEdit->clear();
    ui->textEdit->appendPlainText(info);

}


void GearDesignUI::on_actShowAll_triggered()
{
    if(c_state && b_state){
        ui->textEdit->clear();      //清空文本框
        QStringList strList = m_info->detailedInfo();
        for(int i = 0; i < strList.count(); i++){
            ui->textEdit->appendPlainText(strList.at(i));
        }
    }
    else{
        QMessageBox::warning(this,"警告","设计未完成");
    }
}


void GearDesignUI::on_actShow_triggered()
{
    if(c_state && b_state){
        ui->textEdit->clear();      //清空文本框
        ui->textEdit->appendPlainText(m_info->info());
    }
    else{
        QMessageBox::warning(this,"警告","设计未完成");
    }
}

