// simple_app.h 文件
#pragma execution_character_set("utf-8") //强制转换为UTF-8
#include "include/cef_app.h"
#include "QObject"
// 01: 加入 public QObject父类
class SimpleApp : public QObject, public CefApp, public CefBrowserProcessHandler {
    // 02: 因为要支持 信号槽，所以要加入 Q_OBJECT宏
    Q_OBJECT
 public:
  SimpleApp();
  CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() override {
    return this;
  }
  void OnContextInitialized() override;
// 03： 加入onCefOnctextInitialized信号
signals:
    void onCefOnctextInitialized();

 private:
  IMPLEMENT_REFCOUNTING(SimpleApp);
};

