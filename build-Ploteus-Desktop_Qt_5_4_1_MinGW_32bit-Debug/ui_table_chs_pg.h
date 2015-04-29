/********************************************************************************
** Form generated from reading UI file 'table_chs_pg.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_CHS_PG_H
#define UI_TABLE_CHS_PG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Table_chs_pg
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QPushButton *Add_tbl;
    QSpacerItem *verticalSpacer_2;
    QPushButton *Create_table;
    QSpacerItem *verticalSpacer;
    QLabel *label;

    void setupUi(QWidget *Table_chs_pg)
    {
        if (Table_chs_pg->objectName().isEmpty())
            Table_chs_pg->setObjectName(QStringLiteral("Table_chs_pg"));
        Table_chs_pg->setEnabled(true);
        Table_chs_pg->resize(835, 495);
        verticalLayout = new QVBoxLayout(Table_chs_pg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        Add_tbl = new QPushButton(Table_chs_pg);
        Add_tbl->setObjectName(QStringLiteral("Add_tbl"));
        Add_tbl->setMinimumSize(QSize(0, 50));
        Add_tbl->setStyleSheet(QLatin1String("background-image: url(:/window/Button.png);\n"
"color: rgb(0, 85, 255);\n"
"font: 20pt \"MS Shell Dlg 2\";"));
        Add_tbl->setIconSize(QSize(16777215, 16777215));
        Add_tbl->setCheckable(false);
        Add_tbl->setAutoExclusive(false);
        Add_tbl->setAutoDefault(false);

        gridLayout_2->addWidget(Add_tbl, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 4, 0, 1, 1);

        Create_table = new QPushButton(Table_chs_pg);
        Create_table->setObjectName(QStringLiteral("Create_table"));
        Create_table->setMinimumSize(QSize(0, 50));
        Create_table->setStyleSheet(QLatin1String("background-image: url(:/window/Button.png);\n"
"color: rgb(0, 85, 255);\n"
"font: 20pt \"MS Shell Dlg 2\";"));

        gridLayout_2->addWidget(Create_table, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 178, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);

        label = new QLabel(Table_chs_pg);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/wel_page/Wel_pg1.png")));
        label->setScaledContents(true);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        retranslateUi(Table_chs_pg);

        QMetaObject::connectSlotsByName(Table_chs_pg);
    } // setupUi

    void retranslateUi(QWidget *Table_chs_pg)
    {
        Table_chs_pg->setWindowTitle(QApplication::translate("Table_chs_pg", "Form", 0));
        Add_tbl->setText(QApplication::translate("Table_chs_pg", "Add table", 0));
        Create_table->setText(QApplication::translate("Table_chs_pg", "Create table", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Table_chs_pg: public Ui_Table_chs_pg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_CHS_PG_H
