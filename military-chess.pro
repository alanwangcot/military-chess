QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clientWindow.cpp \
    connectionhandling.cpp \
    dialog.cpp \
    dialog2.cpp \
    dialogdisconnected.cpp \
    gameboard.cpp \
    main.cpp \
    mainwindow.cpp \
#    myserver.cpp \
#    mythread.cpp \
    preparewindow.cpp

HEADERS += \
    clientWindow.h \
    connectionhandling.h \
#    dfsHelper.h \
    dialog.h \
    dialog2.h \
#    g.h \
    dialogdisconnected.h \
    gameboard.h \
    mainwindow.h \
#    myserver.h \
#    mythread.h \
    piece.h \
    preparewindow.h

FORMS += \
    clientWindow.ui \
    dialog.ui \
    dialog2.ui \
    dialogdisconnected.ui \
    mainwindow.ui \
    preparewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
