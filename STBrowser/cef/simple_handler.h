#include "include/cef_client.h"
#include <list>
#include<QObject>

class SimpleHandler : public QObject,
                      public CefClient,
                      public CefLifeSpanHandler{
    Q_OBJECT
 public:
  explicit SimpleHandler(bool use_views);
  ~SimpleHandler();

  // Provide access to the single global instance of this object.
  static SimpleHandler* GetInstance();

  virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override {
      return this;
  }

  // CefLifeSpanHandler methods:
  virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser) override;
  virtual bool DoClose(CefRefPtr<CefBrowser> browser) override;
  virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) override;
  virtual bool OnBeforePopup(CefRefPtr<CefBrowser> browser, //浏览器对象
      CefRefPtr<CefFrame> frame,
      const CefString& target_url, //要打开的地址
      const CefString& target_frame_name,
      WindowOpenDisposition target_disposition,
      bool user_gesture,
      const CefPopupFeatures& popupFeatures,
      CefWindowInfo& windowInfo,
      CefRefPtr<CefClient>& client,
      CefBrowserSettings& settings,
      CefRefPtr<CefDictionaryValue>& extra_info,
      bool* no_javascript_access) override;

   HWND getBrowserWindowHandle() {
        if (!browser_list_.empty()) { //如果集合不为空
            // 获取集合中的第一个 CefBrowser元素 ,获取它的 CefBrowserHost 对象，然后再获取CefBrowserHost 对象中的 WindowHandle 即窗口句柄
            return  browser_list_.front()->GetHost()->GetWindowHandle();
        }
        return NULL;
    }
 private:
  const bool use_views_;

  // List of existing browser windows. Only accessed on the CEF UI thread.
  typedef std::list<CefRefPtr<CefBrowser>> BrowserList;
  BrowserList browser_list_;

  bool is_closing_;

  IMPLEMENT_REFCOUNTING(SimpleHandler);

signals:
    void newPage(QString url);
};
