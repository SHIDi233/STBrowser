#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    soc = new SOCore();
    connect(soc, &SOCore::requestPage, this, &Window::requestPage);

    soc->init();
}

Window::~Window()
{
    delete soc;
    delete ui;
}

void Window::createPage(QString url)
{

}

void Window::on_pushButton_clicked()
{
    QWidget* w=new QWidget(this);
    w->show();
    w->setGeometry(0,0,500,500);

    soc->createPage(w,"www.baidu.com");
}


void Window::on_pushButton_3_clicked()
{
    delete soc;
}


void Window::on_pushButton_2_clicked()
{
    QWidget* w=new QWidget(this);
    w->show();
    w->setGeometry(500,0,500,500);

    soc->createPage(w,"www.bilibili.com");
}

void Window::requestPage(QString url)
{
    QWidget* w=new QWidget(this);
    w->show();
    w->setGeometry(0,0,500,500);

    soc->createPage(w,url);
}
