QT += core gui network widgets
QT += sql

TEMPLATE = app
TARGET = client

MOC_DIR     += generated/mocs
UI_DIR      += generated/uis
RCC_DIR     += generated/rccs
OBJECTS_DIR += generated/objs
SUBDIRS +=Test1

SOURCES += main.cpp\
    auth_window.cpp \
        mainwindow.cpp \
    clientStuff.cpp \
    reg_window.cpp

HEADERS  += mainwindow.h \
    auth_window.h \
    clientStuff.h \
    reg_window.h

FORMS    += mainwindow.ui \
    auth_window.ui \
    reg_window.ui
