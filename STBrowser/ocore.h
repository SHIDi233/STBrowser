#ifndef OCORE_H
#define OCORE_H

#include <QMainWindow>
#include "frame.h"

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

private:
    Ui::OCore *ui;
    int x=0;
    Frame* f;

    void createPage(QString url);
};

#endif // OCORE_H
