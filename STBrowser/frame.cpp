// Frame.cpp 文件
#include "Frame.h"
#include "cef/simple_handler.h"
#include<iostream>
#include "atlbase.h"
#include "atlwin.h"
#include "include/cef_command_line.h"
#include "include/cef_sandbox_win.h"
//#include "cef/simple_app.h"
Frame::Frame(QWidget *parent, QString url)
    : QWidget(parent), url(url), qw((QMainWindow*)parent)
{
    hInstance = GetModuleHandle(nullptr);
    main_args=CefMainArgs(hInstance);
    int exit_code = CefExecuteProcess(main_args, nullptr, nullptr);
    if (exit_code >= 0) {
//        return exit_code;
        std::cout<<"error"<<std::endl;
    }

    settings.no_sandbox = true;
    // 这个设置项将导致CEF在单独的线程上运行Browser的界面，而不是在主线程上。
    settings.multi_threaded_message_loop = true;
    // 创建 SimpleApp 对象
    cefApp=new SimpleApp();

    // 当SimpleApp 中回调OnctextInitialized的时候，通知 主窗体创建浏览器窗口，并嵌入到主窗口中
    connect(cefApp, &SimpleApp::onCefOnctextInitialized, this, &Frame::createBrowserWindow);

    app = CefRefPtr<SimpleApp>(cefApp);
    CefInitialize(main_args, settings, app.get(), nullptr);
}

/// <summary>
/// 创建浏览器窗体 槽函数
/// </summary>
void Frame::createBrowserWindow() {

    std::cout<<"233"<<std::endl;
//    this->qw->setCentralWidget(this);
}

void Frame::open(){
    CefRefPtr<SimpleHandler> handler(new SimpleHandler(false));
    // 浏览器配置，
    CefBrowserSettings browser_settings;
    // 要打开的网址
//    std::string url= "https://www.baidu.com";
    std::string url= this->url.toStdString();
    // 浏览器窗口信息
    CefWindowInfo window_info;

    //window_info.SetAsPopup(NULL, "cefsimple");
    // 获取嵌入窗体的句柄
    HWND wnd = (HWND)this->winId();
    //  CefWindowInfo cefWndInfo;
    CefRect winRect;
    QRect qtRect = this->rect();

    winRect.Set(qtRect.left(),qtRect.top(),qtRect.right()-qtRect.left(),qtRect.bottom()-qtRect.top());


    window_info.SetAsChild(wnd, winRect);

    // Create the first browser window.
    CefBrowserHost::CreateBrowser(window_info, handler, url, browser_settings,
                                  nullptr, nullptr);
}


void Frame::resizeEvent(QResizeEvent* event)
{
    if (SimpleHandler::GetInstance()) {
        HWND wnd = SimpleHandler::GetInstance()->getBrowserWindowHandle();
        if (wnd){
            QRect qtRect = this->rect();
            ::MoveWindow(wnd, qtRect.x(), qtRect.y(), qtRect.width(), qtRect.height(), true);
        }
    }
//    std::cout<<"resize"<<std::endl;
}
