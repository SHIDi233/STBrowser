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

//    CefEnableHighDPISupport();
    HINSTANCE hInstance = GetModuleHandle(nullptr);
    CefMainArgs main_args(hInstance);
    int exit_code = CefExecuteProcess(main_args, nullptr, nullptr);
    if (exit_code >= 0) {
        return exit_code;
    }
    CefSettings settings;
    settings.no_sandbox = true;
    // 这个设置项将导致CEF在单独的线程上运行Browser的界面，而不是在主线程上。
    settings.multi_threaded_message_loop = true;
    // 创建 SimpleApp 对象
    SimpleApp* cefApp=new SimpleApp;
    QApplication a(argc, argv);
    // 为 MainWindow构造方法中传入 SimpleApp
    MainWindow w(cefApp, nullptr);
    w.show();

    CefRefPtr<SimpleApp> app(cefApp);
    CefInitialize(main_args, settings, app.get(), nullptr);
    int ret = a.exec();
    // Shut down CEF.
    CefShutdown();
    return ret;
}
