#-------------------------------------------------
#
# Project created by QtCreator 2015-04-12T11:15:46
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ploteus
TEMPLATE = app


SOURCES += main.cpp\
        ploteuswindow.cpp \
    qcustomplot.cpp \
    aproximator.cpp

HEADERS  += ploteuswindow.h \
    qcustomplot.h \
    aproximator.h

FORMS    += \
    welcome_page.ui \
    table_chs_pg.ui \
    create_table.ui \
    add_table.ui \
    plotting.ui

RESOURCES += \
    resources.qrc

DISTFILES +=
