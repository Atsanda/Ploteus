#-------------------------------------------------
#
# Project created by QtCreator 2015-04-30T15:15:48
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport
QT       += widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ploteus
TEMPLATE = app


SOURCES += main.cpp\
    aproximation.cpp \
    aproximator.cpp \
    file_reading.cpp \
    ploteuswindow.cpp \
    qcustomplot.cpp

HEADERS  += \
    aproximation.h \
    aproximator.h \
    file_reading.h \
    ploteuswindow.h \
    qcustomplot.h

FORMS    += mainwindow.ui \
    add_table.ui \
    create_table.ui \
    ploteuswindow.ui \
    plotting.ui \
    table_chs_pg.ui \
    welcome_page.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    splash.jpg \
    Button.png \
    icon.png \
    Wel_pg1.png \
    Ploteus.pro.user
