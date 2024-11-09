//// Frame.h  文件
//#if _MSC_VER >= 1600   //判断编译器版本（MSVC）
//#pragma execution_character_set("utf-8") //强制转换为UTF-8
//#endif
//#include <QtWidgets>

//class Frame : public QWidget
//{
//    Q_OBJECT
//public:
//    Frame(QWidget* parent = Q_NULLPTR, QString url = "");
//    void resizeEvent(QResizeEvent* event) override;
//    void open();
//// 02 槽函数,完成浏览器窗口的创建与嵌入
//private slots:
//    void createBrowserWindow();
//private:
////    Ui::Frame ui;
//    QString url;
//    QMainWindow* qw;
//    CefRefPtr<SimpleApp> app;
//    HINSTANCE hInstance;
//    CefMainArgs main_args;
//    CefSettings settings;
//    SimpleApp* cefApp;
//};

