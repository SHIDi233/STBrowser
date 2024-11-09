#ifndef OCORE_H
#define OCORE_H

#include <QMainWindow>
//#include "frame.h"
#include "socore.h"

namespace Ui {
class OCore;
}

class OCore : public QMainWindow
{
    Q_OBJECT

public:
    explicit OCore(QWidget *parent = nullptr);
    ~OCore();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::OCore *ui;
    int x=0;
//    Frame* f;

    SOCore* soc;

    void createPage(QString url);
};

#endif // OCORE_H
