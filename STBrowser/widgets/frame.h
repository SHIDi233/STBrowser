#ifndef FRAME_H
#define FRAME_H

#include <QWidget>

namespace Ui {
class Frame;
}

class Frame : public QWidget
{
    Q_OBJECT

public:
    Frame(QWidget *parent = nullptr);
    ~Frame();

    void set_url(QString);

    QWidget* get_box();

private:
    Ui::Frame *ui;

    QString _url;
};

#endif // FRAME_H
