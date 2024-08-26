#ifndef DESIGNVEC_H
#define DESIGNVEC_H
#include "geardesignui.h"
#include "keydesignui.h"
#include "bearingdesignui.h"
#include "axledesignui.h"
#include <QObject>
//设计表类
class Design;
class DesignVec : public QObject
{
    Q_OBJECT
private:
    QList<Design*> m_vec;       //使用多态，以容器储存设计类指针
public:
    explicit DesignVec(QObject *parent = nullptr);
    QString showInfo(int index);        //显示单行设计信息
    QStringList showAll();              //显示所有设计信息
    void addDesign(int type);           //添加设计
    void deleteDesign(int index);       //删除设计
    void deleteAll(){m_vec.clear();}    //删除所有设计
    enum DesignType {TGearDesign, TAxleDesign, TBearingDesign, TKeyDesign};//枚举变量
signals:
};

class Design : public QObject{  //抽象基类
    Q_OBJECT
protected:
    DesignInfo* m_info; //设计信息
    DesignUI* m_UI;     //设计UI
public:
    explicit Design(QObject *parent = nullptr);
    virtual void startDesign() = 0;       //开始设计,纯虚函数
    virtual DesignInfo* info() const {return nullptr;}//返回设计信息
};

class GearDesign : public Design{
    Q_OBJECT
public:
    explicit GearDesign(QObject *parent = nullptr);
    void startDesign() ;       //开始设计,纯虚函数
    DesignInfo* info()const {return m_info;}//返回设计信息

/*private:
    GearDesignUI *m_UI;
    DesignInfo* m_info = nullptr;*/
};

class AxleDesign : public Design{
    Q_OBJECT
public:
    explicit AxleDesign(QObject *parent = nullptr);
    void startDesign() ;       //开始设计,纯虚函数
    DesignInfo* info()const { return m_info;}//返回设计信息
/*private:
    AxleDesignUI* m_UI;
    DesignInfo* m_info = nullptr;*/
};

class KeyDesign : public Design{
    Q_OBJECT
public:
    explicit KeyDesign(QObject *parent = nullptr);
    void startDesign() ;       //开始设计,纯虚函数
    DesignInfo* info()const { return m_info;}//返回设计信息
/*private:
    KeyDesignUI* m_UI;
    DesignInfo* m_info = nullptr;*/
};

class BearingDesign : public Design{
    Q_OBJECT
public:
    explicit BearingDesign(QObject *parent = nullptr);
    void startDesign();       //开始设计,纯虚函数
    DesignInfo* info()const { return m_info;}//返回设计信息
/*private:
    BearingDesignUI *m_UI;
    DesignInfo* m_info = nullptr;*/
};


#endif // DESIGNVEC_H
