#ifndef SOCORE_H
#define SOCORE_H
#include "atlbase.h"
#include "atlwin.h"
#include "include/cef_command_line.h"
#include "include/cef_sandbox_win.h"
#include "cef/simple_handler.h"
#include<iostream>
#include<QObject>
#include "cef/simple_app.h"

class SOCore : public QObject
{
    Q_OBJECT
public:
    SOCore();
    ~SOCore();

    bool init();//初始化外核

    int createPage(QWidget*, QString);//加载新页面
private:
    //CEF相关
    CefRefPtr<SimpleApp> app;
    HINSTANCE hInstance;
    CefMainArgs main_args;
    CefSettings settings;
    SimpleApp* cefApp;
    SimpleHandler* handle;

    //页面管理相关
    int _h_id=0;//最高页面数id，随页面打开递增分配
private slots:
    void loaded();
    void newPage(QString url);
signals:
    void requestPage(QString url);
};

#endif // SOCORE_H
