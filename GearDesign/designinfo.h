#ifndef DESIGNINFO_H
#define DESIGNINFO_H

#include <QObject>

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

#endif // DESIGNINFO_H
