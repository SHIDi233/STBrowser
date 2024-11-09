#ifndef STAB_H
#define STAB_H
#include <QPushButton>

class STab : public QPushButton
{
public:
    STab(int id);

    void set_title();
private:
    int _id;//Tab归属frame的id
    QString _text;//frame的标题
    //TO_DO:图像等数据
};

#endif // STAB_H
