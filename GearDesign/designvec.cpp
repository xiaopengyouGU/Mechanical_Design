#include "designvec.h"

DesignVec::DesignVec(QObject *parent)
    : QObject{parent}
{}

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
        tmpDesign = new GearDesign(this);
        m_vec.append(tmpDesign);break;
    case TAxleDesign:
        tmpDesign = new AxleDesign(this);
        m_vec.append(tmpDesign);break;
    case TKeyDesign:
        tmpDesign = new GearDesign(this);
        m_vec.append(tmpDesign);break;
    case TBearingDesign:
        tmpDesign = new GearDesign(this);
        m_vec.append(tmpDesign);break;
    default:
        break;
    }
}

void DesignVec::deleteDesign(int index)
{
    if(index < 0 || index >= m_vec.count())
        return;
    m_vec.remove(index);            //移除一个设计
}

GearDesign::GearDesign(QObject *parent):Design(parent)
{
    m_info = new DesignInfo(this);  //创建设计信息变量
}

void GearDesign::startDesign()
{
    m_UI = new GearDesignUI;    //创建UI
    m_UI->show();//显示UI界面
    m_UI->startDesign(m_info);
}

AxleDesign::AxleDesign(QObject *parent):Design(parent)
{
    m_info = new DesignInfo(this);  //创建设计信息变量
}

void AxleDesign::startDesign()
{
    m_UI = new AxleDesignUI;    //创建UI
    m_UI->show();//显示UI界面
    m_UI->startDesign(m_info);
}

KeyDesign::KeyDesign(QObject *parent):Design(parent)
{
    m_info = new DesignInfo(parent);  //创建设计信息变量
}

void KeyDesign::startDesign()
{
    m_UI = new KeyDesignUI;
    m_UI->show();//显示UI界面
    m_UI->startDesign(m_info);
}

BearingDesign::BearingDesign(QObject *parent):Design(parent)
{
    m_info = new DesignInfo(this);  //创建设计信息变量
}

void BearingDesign::startDesign()
{
    m_UI = new BearingDesignUI;    //创建UI
    m_UI->show();//显示UI界面
    m_UI->startDesign(m_info);
}

Design::Design(QObject *parent):QObject(parent)
{
}
