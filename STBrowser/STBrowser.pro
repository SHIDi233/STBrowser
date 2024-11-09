QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cef/simple_app.cc \
    cef/simple_handler.cc \
    frame.cpp \
    main.cpp \
    socore.cpp \
    window.cpp

HEADERS += \
    cef/simple_app.h \
    cef/simple_handler.h \
    frame.h \
    socore.h \
    window.h

FORMS += \
 window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libs/cef/lib/ -llibcef
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libs/cef/lib/ -llibcefd
else:unix: LIBS += -L$$PWD/libs/cef/lib/ -llibcef

INCLUDEPATH += $$PWD/libs/cef
DEPENDPATH += $$PWD/libs/cef

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libs/cef/lib/ -llibcef_dll_wrapper
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libs/cef/lib/ -llibcef_dll_wrapperd
else:unix: LIBS += -L$$PWD/libs/cef/lib/ -llibcef_dll_wrapper

INCLUDEPATH += $$PWD/libs/cef
DEPENDPATH += $$PWD/libs/cef

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libs/cef/lib/ -llibcef
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libs/cef/lib/ -llibcefd
else:unix: LIBS += -L$$PWD/libs/cef/lib/ -llibcef

INCLUDEPATH += $$PWD/libs/cef/lib
DEPENDPATH += $$PWD/libs/cef/lib

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libs/cef/lib/ -llibcef_dll_wrapper
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libs/cef/lib/ -llibcef_dll_wrapperd
else:unix: LIBS += -L$$PWD/libs/cef/lib/ -llibcef_dll_wrapper

INCLUDEPATH += $$PWD/libs/cef/lib
DEPENDPATH += $$PWD/libs/cef/lib

msvc{
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
    # QMAKE_CXXFLAGS += /source-charset:utf-8 /execution-charset:utf-8
}

