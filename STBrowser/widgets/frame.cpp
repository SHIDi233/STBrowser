#include "frame.h"
#include "ui_frame.h"

Frame::Frame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Frame)
{
    ui->setupUi(this);
}

Frame::~Frame()
{
    delete ui;
}

QWidget* Frame::get_box(){
    return ui->box;
}
