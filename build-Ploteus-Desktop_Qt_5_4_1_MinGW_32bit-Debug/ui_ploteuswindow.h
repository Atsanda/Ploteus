/********************************************************************************
** Form generated from reading UI file 'ploteuswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTEUSWINDOW_H
#define UI_PLOTEUSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PloteusWindow
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PloteusWindow)
    {
        if (PloteusWindow->objectName().isEmpty())
            PloteusWindow->setObjectName(QStringLiteral("PloteusWindow"));
        PloteusWindow->resize(400, 300);
        menuBar = new QMenuBar(PloteusWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        PloteusWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PloteusWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PloteusWindow->addToolBar(mainToolBar);
        centralWidget = new QWidget(PloteusWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        PloteusWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(PloteusWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PloteusWindow->setStatusBar(statusBar);

        retranslateUi(PloteusWindow);

        QMetaObject::connectSlotsByName(PloteusWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PloteusWindow)
    {
        PloteusWindow->setWindowTitle(QApplication::translate("PloteusWindow", "PloteusWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class PloteusWindow: public Ui_PloteusWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTEUSWINDOW_H
