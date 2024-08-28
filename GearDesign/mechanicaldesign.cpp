#include "mechanicaldesign.h"
#include "ui_mechanicaldesign.h"
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QSqlError>
#include <QDate>
#include <QLabel>
void MechanicalDesign::OpenTable()
{//创建数据模型，打开数据表
    tabModel = new QSqlTableModel(this,DB);
    tabModel->setTable("designInfo");
    tabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);  //数据保存方式
    tabModel->setSort(tabModel->fieldIndex("Type"),Qt::AscendingOrder); //排序方式
    if(!(tabModel->select())){                  //查询数据失败
        QMessageBox::critical(this,"错误信息","打开数据表错误,错误信息：\n"+tabModel->lastError().text());
        return;
    }
    //显示记录条数
    showRecordCount();
    base = tabModel->rowCount();        //历史设计的数量
    //设置字段显示标题
    tabModel->setHeaderData(tabModel->fieldIndex("Label"),Qt::Horizontal,"设计标签");
    tabModel->setHeaderData(tabModel->fieldIndex("Type"),Qt::Horizontal,"设计种类");
    tabModel->setHeaderData(tabModel->fieldIndex("Level"),Qt::Horizontal,"精度");
    tabModel->setHeaderData(tabModel->fieldIndex("Material"),Qt::Horizontal,"材料");
    tabModel->setHeaderData(tabModel->fieldIndex("Meme"),Qt::Horizontal,"主要设计信息");
    //创建选择模型
    selModel = new QItemSelectionModel(tabModel,this);
    //当前行变化时，发射currentRowChanged信号
    connect(selModel,&QItemSelectionModel::currentRowChanged,this,&MechanicalDesign::do_currentRowChanged);
    //模型视图结构
    ui->tableView->setModel(tabModel);
    ui->tableView->setSelectionModel(selModel);
    ui->tableView->setColumnHidden(tabModel->fieldIndex("Meme"),true);

    //创建界面组件与模型字段的数据映射
    dataMapper = new QDataWidgetMapper(this);
    dataMapper->setModel(tabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
    //与具体字段的映射
    dataMapper->addMapping(ui->textEdit,tabModel->fieldIndex("Meme"));  //显示主要设计信息
    dataMapper->toFirst();              //移动到首记录
    //更新界面组件的使能状态
    ui->actOpenDB->setEnabled(false);
    ui->actSave->setEnabled(true);
}

void MechanicalDesign::do_currentRowChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(current);
    dataMapper->setCurrentIndex(current.row());
}

void MechanicalDesign::showRecordCount()
{
    QString str = QString::asprintf("设计数量：%d",tabModel->rowCount());
    labCount->setText(str);
}

MechanicalDesign::MechanicalDesign(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MechanicalDesign)
{
    ui->setupUi(this);
    m_Vec = new DesignVec(this);        //创建设计表对象
    this->resize(750,500);
    //完成一个设计时，添加一条设计信息
    connect(m_Vec,&DesignVec::finishADesign,this,&MechanicalDesign::do_addDesign);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //行选择
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);//单项选择
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);  //不可编辑
    ui->tableView->setAlternatingRowColors(true);
    //状态栏标签显示
    labCount = new QLabel("设计数量：");
    labCount->setMinimumWidth(150);
    ui->statusbar->addWidget(labCount);
    QString date = "设计日期："+QDate::currentDate().toString("yyyy-MM-dd");
    labDate = new QLabel(date);     //显示设计日期
    labDate->setMinimumWidth(150);
    ui->statusbar->addWidget(labDate);
    labInfo = new QLabel("使用说明见：");
    labInfo->setMinimumWidth(250);
    ui->statusbar->addWidget(labInfo);

}

MechanicalDesign::~MechanicalDesign()
{
    delete ui;
}

void MechanicalDesign::do_addDesign(int index)
{//在数据库中添加一条设计信息
    if(tabModel == nullptr){
        return; //没有打开数据库的话
    }
    DesignInfo* tmpInfo = m_Vec->infoFromIndex(index);  //返回一条设计信息
    if(tmpInfo == nullptr)//判断返回信息是否有效
        return;
    QSqlRecord rec = tabModel->record(); //获取一条空记录，只有字段定义
    int val = (tabModel->rowCount() + 1)%100 * 1000 + QRandomGenerator::global()->bounded(11,999);
    //随机生成一段标签序列号
    QString Label = QDate::currentDate().toString("yyyy-MM-dd")+"-"+QString::number(val);
    rec.setValue(tabModel->fieldIndex("Label"),Label);
    rec.setValue(tabModel->fieldIndex("Type"),tmpInfo->type());
    rec.setValue(tabModel->fieldIndex("Level"),tmpInfo->level());
    rec.setValue(tabModel->fieldIndex("Material"),tmpInfo->material());
    rec.setValue(tabModel->fieldIndex("Meme"),tmpInfo->info());
    tabModel->insertRecord(tabModel->rowCount(),rec);   //插入数据模型的最后

    selModel->clearSelection();
    QModelIndex curIndex = tabModel->index(tabModel->rowCount()-1,1);
    selModel->setCurrentIndex(curIndex,QItemSelectionModel::Select);//设置当前行
    showRecordCount();
    ui->actSave->setEnabled(true);  //使能保存按钮
}

void MechanicalDesign::on_actGear_triggered()
{
    m_Vec->addDesign(DesignVec::TGearDesign);   //添加设计

}


void MechanicalDesign::on_actKey_triggered()
{
    m_Vec->addDesign(DesignVec::TKeyDesign);
}


void MechanicalDesign::on_actAxle_triggered()
{
    m_Vec->addDesign(DesignVec::TAxleDesign);
}


void MechanicalDesign::on_actBearing_triggered()
{
    m_Vec->addDesign(DesignVec::TBearingDesign);
}


void MechanicalDesign::on_btnDeleteAll_clicked()
{
    m_Vec->deleteAll();     //删除所有设计
    if(tabModel == nullptr)
        return;
    tabModel->removeRows(0,tabModel->rowCount());   //删除所有设计
    base = 0;               //历史设计数量清零
    ui->actSave->setEnabled(true);
}


void MechanicalDesign::on_actOutput_triggered()
{//输出本次设计信息
    QString dlgTitle = "输出本次设计信息到文件";
    QString filter = "文本文件(*.txt);;所有文件(*.*)";
    QString curPath = QDir::currentPath();
    QString aFileName = QFileDialog::getSaveFileName(this,dlgTitle,curPath,filter);
    if(aFileName.isEmpty())
        return;
    //利用QFile输出设计信息
    QFile aFile(aFileName);
    if(!aFile.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QString str = "*******本次设计的信息*******\n\n";
    QStringList strList = m_Vec->showAll(); //所有设计信息
    for(int i = 0; i < strList.count();i++){
        str += strList.at(i);
        str += "\n";
    }
    QByteArray strBytes = str.toUtf8();
    aFile.write(strBytes,strBytes.length());
    aFile.close();
    QMessageBox::information(this,"信息","设计信息输出完毕");
}


void MechanicalDesign::on_actOpenDB_triggered()
{//打开数据库
    QString curPath = QDir::currentPath();
    QString aFile = QFileDialog::getOpenFileName(this,"选择文件",curPath,"SQLite数据库(*.db)");
    if(aFile.isEmpty())
        return;
    //打开数据库
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName(aFile);
    //不考虑密码，用户名
    if(!DB.open())
        QMessageBox::warning(this,"错误","打开数据库失败");
    else
        OpenTable();                    //打开数据表
}


void MechanicalDesign::on_btnDelete_clicked()
{
    if(tabModel == nullptr)
        return;
    QModelIndex curIndex = selModel->currentIndex();
    int index = curIndex.row();
    if(index >= base){//本次设计
        m_Vec->deleteDesign(index - base);
    }
    else{
        base -= 1;  //历史设计减1
    }
    tabModel->removeRow(index);
    ui->actSave->setEnabled(true);
    showRecordCount();
}


void MechanicalDesign::on_actSave_triggered()
{//保存设计
    bool res = tabModel->submitAll();
    if(!res){
        QMessageBox::information(this,"消息","数据保存错误，错误信息\n"+tabModel->lastError().text());
    }
    else{
        ui->actSave->setEnabled(false);
    }
    showRecordCount();
}

void MechanicalDesign::on_radioGear_clicked()
{
    tabModel->setFilter("Type = '齿轮设计'");
    showRecordCount();
}


void MechanicalDesign::on_radioKey_clicked()
{
    tabModel->setFilter("Type = '键的设计'");
    showRecordCount();
}


void MechanicalDesign::on_radioBearing_clicked()
{
    tabModel->setFilter("Type = '轴承设计'");
    showRecordCount();
}


void MechanicalDesign::on_radioAxle_clicked()
{
    tabModel->setFilter("Type = '轴的设计'");
    showRecordCount();
}



void MechanicalDesign::on_radioAll_clicked()
{
    tabModel->setFilter("");    //显示所有设计
    showRecordCount();
}


void MechanicalDesign::on_chkSort_clicked(bool checked)
{
    if(checked){
        tabModel->setSort(tabModel->fieldIndex("Label"),Qt::DescendingOrder); //排序方式
    }
    else{
        tabModel->setSort(tabModel->fieldIndex("Type"),Qt::AscendingOrder); //排序方式
    }
    tabModel->submitAll();  //提交所有
}


