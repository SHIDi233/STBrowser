#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include "include/cef_command_line.h"
#include "include/cef_sandbox_win.h"
//#include "cef/simple_app.h"
#include <qdebug.h>
#include<QTextCodec>
int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QApplication a(argc, argv);
    // 为 MainWindow构造方法中传入 SimpleApp
    MainWindow w(nullptr);
    w.show();
    int ret = a.exec();

    // Shut down CEF.
    CefShutdown();
    return ret;
}
