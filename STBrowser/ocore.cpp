#include "ocore.h"
#include "ui_ocore.h"

OCore::OCore(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OCore)
{
    ui->setupUi(this);
//    QString url = "www.baidu.com";
//    f=new Frame(this,url);
//    f->setParent(this);
//    f->setGeometry(0,0,100,100);
//    f->setStyleSheet("background-color: red;");
//    f->show();
////    f->set
//    this->setCentralWidget(f);
//    createPage("https://www.baidu.com");
    soc = new SOCore();
    soc->init();
}

OCore::~OCore()
{
    delete soc;
    delete ui;
}

void OCore::createPage(QString url)
{

}

void OCore::on_pushButton_clicked()
{
//    f->open();
    QWidget* w=new QWidget(this);
    w->show();
    w->setGeometry(0,0,500,500);

    soc->createPage(w,"www.baidu.com");
}


void OCore::on_pushButton_3_clicked()
{
    delete soc;
}


void OCore::on_pushButton_2_clicked()
{
    QWidget* w=new QWidget(this);
    w->show();
    w->setGeometry(500,0,500,500);

    soc->createPage(w,"www.bilibili.com");
}

