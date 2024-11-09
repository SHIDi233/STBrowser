#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "socore.h"
#include <QList>
#include "widgets/frame.h"
#include "widgets/stab.h"

struct frame{
    Frame* _w_p;
    int _id;
};

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
    void requestPage(QString url);

    void on_pushButton_clicked();

private:
    Ui::Window *ui;

    SOCore* soc;

    QList<frame> frames;

    void createPage(QString url);
};

#endif // WINDOW_H
