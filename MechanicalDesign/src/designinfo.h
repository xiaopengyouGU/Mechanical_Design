#ifndef DESIGNINFO_H
#define DESIGNINFO_H

#include <QObject>
#include <QMainWindow>
//设计信息类
class DesignInfo : public QObject
{
    Q_OBJECT
private:
    int m_level;                   //设计精度
    QString m_material;               //材料
    QString m_type;                   //设计种类
    QString m_info;                   //主要设计信息
    QStringList m_detailedInfo;           //详细设计信息
public:
    DesignInfo(QObject*parent);     //设计信息类
    ~DesignInfo();

    int level() const{ return m_level;}
    QString material() const{return m_material;}
    QString type() const {return m_type;}
    QString info() const{return m_info;}
    QStringList detailedInfo() const {return m_detailedInfo;}

    void setLevel(int val){ m_level = val;}
    void setMaterial(QString mat) { m_material = mat;}
    void setType(QString type) {m_type = type;}
    void setInfo(QString info) {m_info = info;}
    void setDetailedInfo(QStringList detailed) { m_detailedInfo = detailed;}
    void appendInfo(QString& str) { m_detailedInfo << str;} //添加信息
    void clearInfo(){m_info = "", m_detailedInfo.clear();}  //清空信息
};
//设计UI类
class DesignUI : public QMainWindow{
    Q_OBJECT
protected:
    DesignInfo* m_info;
signals:
    void finishDesign();        //完成设计信号
public:
    explicit DesignUI(QWidget *parent = nullptr);
    ~DesignUI();
    virtual void startDesign(DesignInfo* info){} //两个虚函数
protected:
    virtual void reFresh(){}
};

#endif // DESIGNINFO_H
