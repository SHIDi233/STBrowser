#include "window.h"
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

    Window oc;
    oc.show();
    int ret = a.exec();
    return ret;
}
