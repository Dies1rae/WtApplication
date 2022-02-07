TEMPLATE = app

CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L/usr/lib -lwt -lwthttp -lwtdbo -lwtdbosqlite3 -I/usr/local/include
LIBS += -L/usr/local/lib -lwthttp -lwt -lboost_regex -lboost_signals
LIBS += -lboost_system -lboost_thread -lboost_filesystem -lboost_date_time -lpthread -lcrypt

SOURCES += \
        LoginPage.cpp \
        MainApp.cpp \
        MainPage.cpp \
        UserAccount.cpp \
        main.cpp

HEADERS += \
    Entry.h \
    LoginPage.h \
    MainApp.h \
    MainPage.h \
    UserAccount.h

#QT += core
