// mainwindow.h  文件
#if _MSC_VER >= 1600   //判断编译器版本（MSVC）
#pragma execution_character_set("utf-8") //强制转换为UTF-8
#endif
#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "cef/simple_app.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    // 01 传入SimpleApp ,用于连接到它的onCefOnctextInitialized 信号
    MainWindow(SimpleApp* cefApp,QWidget* parent = Q_NULLPTR);
    void resizeEvent(QResizeEvent* event) override;
// 02 槽函数,完成浏览器窗口的创建与嵌入
private slots:
    void createBrowserWindow();
private:
    SimpleApp*  m_cefApp=NULL;
    Ui::MainWindow ui;
};

