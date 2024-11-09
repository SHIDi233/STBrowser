#include "socore.h"
#include<QWidget>
#include<QMessageBox>

SOCore::SOCore(){

}

bool SOCore::init(){
    //加载Chromium内核
    hInstance = GetModuleHandle(nullptr);
    main_args=CefMainArgs(hInstance);
    int exit_code = CefExecuteProcess(main_args, nullptr, nullptr);
    if (exit_code >= 0) {
        return false;
    }
    //禁用sand_box
    settings.no_sandbox = true;
    // 这个设置项将导致CEF在单独的线程上运行Browser的界面，而不是在主线程上。
    settings.multi_threaded_message_loop = true;
    // 创建 SimpleApp 对象
    cefApp=new SimpleApp();

    // 当SimpleApp 中回调OnctextInitialized的时候，通知窗体创建浏览器窗口，并嵌入到主窗口中
    connect(cefApp, &SimpleApp::onCefOnctextInitialized, this, &SOCore::loaded);

    app = CefRefPtr<SimpleApp>(cefApp);
    CefInitialize(main_args, settings, app.get(), nullptr);
    return true;
}

SOCore::~SOCore(){
    CefShutdown();
}

void SOCore::loaded() {
    std::cout<<"(SOCore)Msg:Chromium core has loaded"<<std::endl;
}

void SOCore::newPage(QString url){
//    createPage(url);
    std::cout<<"(SOC)Msg:New page from core"<<std::endl;
    emit requestPage(url);
}

int SOCore::createPage(QWidget* parent, QString url){
    QMessageBox::StandardButton response = QMessageBox::question(nullptr, "标题", "外部创建接口被调用",
                                                                    QMessageBox::Yes | QMessageBox::No);
    handle = new SimpleHandler(false);
    connect(handle, &SimpleHandler::newPage, this, &SOCore::newPage);
    CefRefPtr<SimpleHandler> handler(handle);
    // 浏览器配置，
    CefBrowserSettings browser_settings;
    // 要打开的网址
    std::string _url= url.toStdString();
    // 浏览器窗口信息
    CefWindowInfo window_info;

    //window_info.SetAsPopup(NULL, "cefsimple");
    // 获取嵌入窗体的句柄
    HWND wnd = (HWND)parent->winId();
    //  CefWindowInfo cefWndInfo;
    CefRect winRect;
    QRect qtRect = parent->rect();

    winRect.Set(qtRect.left(),qtRect.top(),qtRect.right()-qtRect.left(),qtRect.bottom()-qtRect.top());


    window_info.SetAsChild(wnd, winRect);

    // Create the first browser window.
    CefBrowserHost::CreateBrowser(window_info, handler, _url, browser_settings,
                                  nullptr, nullptr);
    return _h_id++;
}
