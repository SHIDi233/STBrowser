#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "socore.h"

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void requestPage(QString url);

private:
    Ui::Window *ui;

    SOCore* soc;

    void createPage(QString url);
};

#endif // WINDOW_H
