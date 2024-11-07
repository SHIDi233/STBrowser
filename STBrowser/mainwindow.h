// mainwindow.h  文件
#if _MSC_VER >= 1600   //判断编译器版本（MSVC）
#pragma execution_character_set("utf-8") //强制转换为UTF-8
#endif
#include <QtWidgets>
//#include "ui_mainwindow.h"
#include "cef/simple_app.h"
class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget* parent = Q_NULLPTR);
    void resizeEvent(QResizeEvent* event) override;
// 02 槽函数,完成浏览器窗口的创建与嵌入
private slots:
    void createBrowserWindow();
private:
//    Ui::MainWindow ui;
};

