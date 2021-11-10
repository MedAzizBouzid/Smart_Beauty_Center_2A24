QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

   TARGET=DuMessengerLANClient
TEMPLATE=app

SOURCES +=  DuMessengerConnectionDialog.cpp \
    main.cpp \
    widget.cpp

HEADERS +=   DuMessengerConnectionDialog.h \
    widget.h

FORMS +=   DuMessengerConnectionDialog.ui \
    widget.ui


QMAKE_CXXFLAGS +=-std=gnu++11
