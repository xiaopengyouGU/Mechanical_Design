#include "designvec.h"

DesignVec::DesignVec(QObject *parent)
    : QObject{parent}
{
}

QString DesignVec::showInfo(int index)
{
    if(index < 0 || index >= m_vec.count())
        return "";
    DesignInfo * tmpInfo = m_vec.at(index)->info(); //获取设计信息
    return tmpInfo->info();         //返回主要设计信息
}

QStringList DesignVec::showAll()
{
    QStringList strList;
    DesignInfo*tmpInfo;
    for(int i = 0; i < m_vec.count();i++){
        tmpInfo = m_vec.at(i)->info();
        strList << tmpInfo->info();         //输入主要设计信息
    }
    return strList;
}

void DesignVec::addDesign(int type)
{
    Design * tmpDesign = nullptr;
    switch(type){
    case TGearDesign:
        tmpDesign = new GearDesign(this);break;
    case TAxleDesign:
        tmpDesign = new AxleDesign(this);break;
    case TKeyDesign:
        tmpDesign = new KeyDesign(this);break;
    case TBearingDesign:
        tmpDesign = new BearingDesign(this);break;
    default:
        break;
    }
    if(tmpDesign != nullptr){
        m_vec.append(tmpDesign);        //添加设计对象
        //建立连接
        connect(tmpDesign,&Design::finishADesign,this,&DesignVec::do_finishADesign);
        tmpDesign->startDesign();       //启动设计UI
    }
}

void DesignVec::deleteDesign(int index)
{
    if(index < 0 || index >= m_vec.count())
        return;
    m_vec.remove(index);            //移除一个设计
}

DesignInfo *DesignVec::infoFromIndex(int index)
{
    if(index < 0 || index >= m_vec.count())
        return nullptr;
    else
        return m_vec.at(index)->info();
}

void DesignVec::do_finishADesign()
{//需要知道信息发送者的在设计表中的位置
    Design* object = static_cast<Design*>(sender());     //信号发送者
    int index = -1;     //对应的位置
    for(int i = 0; i < m_vec.count();i++){
        if(object == m_vec.at(i)){
            index = i;
            break;
        }
    }
    emit finishADesign(index);  //发送完成一个设计的信号
}

GearDesign::GearDesign(QObject *parent):Design(parent)
{

}

void GearDesign::startDesign()
{
    m_UI = new GearDesignUI;    //创建UI
    m_UI->show();//显示UI界面
    m_UI->startDesign(m_info);
    //连接信号与槽函数
    connect(m_UI,&DesignUI::finishDesign,this,&Design::do_finishDesign);
}

AxleDesign::AxleDesign(QObject *parent):Design(parent)
{

}

void AxleDesign::startDesign()
{
    m_UI = new AxleDesignUI;    //创建UI
    m_UI->show();//显示UI界面
    m_UI->startDesign(m_info);
    //连接信号与槽函数
    connect(m_UI,&DesignUI::finishDesign,this,&Design::do_finishDesign);
}

KeyDesign::KeyDesign(QObject *parent):Design(parent)
{
}

void KeyDesign::startDesign()
{
    m_UI = new KeyDesignUI;
    m_UI->show();//显示UI界面
    m_UI->startDesign(m_info);
    //连接信号与槽函数
    connect(m_UI,&DesignUI::finishDesign,this,&Design::do_finishDesign);
}

BearingDesign::BearingDesign(QObject *parent):Design(parent)
{
}

void BearingDesign::startDesign()
{
    m_UI = new BearingDesignUI;    //创建UI
    m_UI->show();//显示UI界面
    m_UI->startDesign(m_info);
    //连接信号与槽函数
    connect(m_UI,&DesignUI::finishDesign,this,&Design::do_finishDesign);
}

void Design::do_finishDesign()
{
    emit finishADesign();   //发送完成一个设计信号
}

Design::Design(QObject *parent):QObject(parent)
{
    m_info = new DesignInfo(parent);
}
