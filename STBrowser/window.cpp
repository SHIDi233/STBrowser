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




void Window::requestPage(QString url)
{
//    QWidget* w=new QWidget(this->ui->box);
//    w->show();
//    w->setGeometry(0,0,500,500);

//    int ret=soc->createPage(w,"www.baidu.com");
//    if(ret==-1){

//    }
//    else{
//        frame f({w,ret});
//        frames.append(f);
//    }
}



void Window::on_pushButton_clicked(){
    Frame* f = new Frame((QWidget*)this->ui->box);
    f->show();
    f->setGeometry(0,0,500,500);

    int ret=soc->createPage(f->get_box(),"www.baidu.com");
    if(ret==-1){

    }
    else{
        frames.append({f,ret});
    }
}

