﻿// mainwindow.cpp 文件
#include "mainwindow.h"
#include "cef/simple_handler.h"
#include<iostream>
#include "atlbase.h"
#include "atlwin.h"
MainWindow::MainWindow(SimpleApp* cefApp,QWidget *parent)
    : QMainWindow(parent),m_cefApp(cefApp)
{
    ui.setupUi(this);
    // 当SimpleApp 中回调OnctextInitialized的时候，通知 主窗体创建浏览器窗口，并嵌入到主窗口中
    connect(m_cefApp, &SimpleApp::onCefOnctextInitialized, this, &MainWindow::createBrowserWindow);
}

/// <summary>
/// 创建浏览器窗体 槽函数
/// </summary>
void MainWindow::createBrowserWindow() {
    CefRefPtr<SimpleHandler> handler(new SimpleHandler(false));
    // 浏览器配置，
    CefBrowserSettings browser_settings;
    // 要打开的网址
    std::string url= "https://www.baidu.com";
    // 浏览器窗口信息
    CefWindowInfo window_info;

    //window_info.SetAsPopup(NULL, "cefsimple");
    // 获取嵌入窗体的句柄
    HWND wnd = (HWND)this->centralWidget()->winId();
    //  CefWindowInfo cefWndInfo;
    CefRect winRect;
    QRect qtRect = this->rect();
    //  winRect.left = qtRect.left();
    //  winRect.top = qtRect.top();
    //  winRect.right = qtRect.right();
    //  winRect.bottom = qtRect.bottom();
    winRect.Set(qtRect.left(),qtRect.top(),qtRect.right()-qtRect.left(),qtRect.bottom()-qtRect.top());


    window_info.SetAsChild(wnd, winRect);
    // Create the first browser window.
    CefBrowserHost::CreateBrowser(window_info, handler, url, browser_settings,
                                  nullptr, nullptr);
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    if (SimpleHandler::GetInstance()) {
        HWND wnd = SimpleHandler::GetInstance()->getBrowserWindowHandle();
        if (wnd){
            QRect qtRect = this->centralWidget()->rect();
            ::MoveWindow(wnd, qtRect.x(), qtRect.y(), qtRect.width(), qtRect.height(), true);
        }
    }
//    std::cout<<"resize"<<std::endl;
}
