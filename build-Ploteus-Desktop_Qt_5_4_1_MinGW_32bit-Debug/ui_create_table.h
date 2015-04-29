/********************************************************************************
** Form generated from reading UI file 'create_table.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_TABLE_H
#define UI_CREATE_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Create_table
{
public:
    QTableWidget *tableWidget;

    void setupUi(QWidget *Create_table)
    {
        if (Create_table->objectName().isEmpty())
            Create_table->setObjectName(QStringLiteral("Create_table"));
        Create_table->resize(851, 489);
        tableWidget = new QTableWidget(Create_table);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 256, 192));

        retranslateUi(Create_table);

        QMetaObject::connectSlotsByName(Create_table);
    } // setupUi

    void retranslateUi(QWidget *Create_table)
    {
        Create_table->setWindowTitle(QApplication::translate("Create_table", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Create_table: public Ui_Create_table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_TABLE_H
