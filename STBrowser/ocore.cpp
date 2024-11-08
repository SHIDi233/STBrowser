#include "ocore.h"
#include "ui_ocore.h"
#include "atlbase.h"
#include "atlwin.h"
#include "include/cef_command_line.h"
#include "include/cef_sandbox_win.h"
#include "cef/simple_handler.h"

OCore::OCore(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OCore)
{
    ui->setupUi(this);
    QString url = "www.baidu.com";
    f=new Frame(this,url);
    f->setParent(this);
    f->setGeometry(0,0,100,100);
    f->setStyleSheet("background-color: red;");
    f->show();
//    f->set
    this->setCentralWidget(f);
//    createPage("https://www.baidu.com");
}

OCore::~OCore()
{
    CefShutdown();
    delete ui;
}

void OCore::createPage(QString url)
{

}

void OCore::on_pushButton_clicked()
{
    f->open();
}

