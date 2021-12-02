QT       += core gui sql texttospeech

QT += svg
QT       += printsupport
QT       += core gui serialport
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
        QT += widgets
QT       += core gui network

QT       += core gui charts


TARGET = untitled
TEMPLATE = app
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
CONFIG += c++11

SOURCES += \
    client.cpp \
    connexion.cpp \
    dialog.cpp \
    employe.cpp \
    fournisseur.cpp \
    main.cpp \
    mainwindow.cpp \
    notepad.cpp \
    produit.cpp \
    qrcode.cpp \
    service.cpp \
    smtp.cpp

HEADERS += \
    client.h \
    connexion.h \
    dialog.h \
    employe.h \
    fournisseur.h \
    mainwindow.h \
    notepad.h \
    produit.h \
    qrcode.h \
    service.h \
    smtp.h

FORMS += \
    dialog.ui \
    mainwindow.ui \
    notepad.ui
QMAKE_CXXFLAGS +=-std=gnu++14

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    243530218_1310825109377240_1931357582866907769_n.ico \
    SyNet.qss

RESOURCES += \
    photos.qrc
