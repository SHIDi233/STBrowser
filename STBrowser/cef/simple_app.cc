// simple_app.cc 文件
#include "simple_app.h"
#include <string>
#include "include/cef_browser.h"
#include "include/views/cef_window.h"
#include "include/wrapper/cef_helpers.h"
#include "simple_handler.h"
SimpleApp::SimpleApp()
{
}
// 04: 在 OnContextInitialized 中发射onCefOnctextInitialized信号
void SimpleApp::OnContextInitialized() {
  CEF_REQUIRE_UI_THREAD();
  // 发出信号
  emit onCefOnctextInitialized();
}
