/********************************************************************************
** Form generated from reading UI file 'welcome_page.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_PAGE_H
#define UI_WELCOME_PAGE_H

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

class Ui_Welcome_Page
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QPushButton *StartButton;

    void setupUi(QWidget *Welcome_Page)
    {
        if (Welcome_Page->objectName().isEmpty())
            Welcome_Page->setObjectName(QStringLiteral("Welcome_Page"));
        Welcome_Page->setEnabled(true);
        Welcome_Page->resize(851, 489);
        verticalLayout = new QVBoxLayout(Welcome_Page);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 178, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 3, 0, 1, 1);

        label = new QLabel(Welcome_Page);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/wel_page/Wel_pg1.png")));
        label->setScaledContents(true);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        StartButton = new QPushButton(Welcome_Page);
        StartButton->setObjectName(QStringLiteral("StartButton"));
        StartButton->setMinimumSize(QSize(0, 50));
        StartButton->setStyleSheet(QLatin1String("background-image: url(:/window/Button.png);\n"
"color: rgb(0, 85, 255);\n"
"font: 20pt \"MS Shell Dlg 2\";"));
        StartButton->setIconSize(QSize(16777215, 16777215));
        StartButton->setCheckable(false);
        StartButton->setAutoExclusive(false);
        StartButton->setAutoDefault(false);

        gridLayout_2->addWidget(StartButton, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        retranslateUi(Welcome_Page);

        QMetaObject::connectSlotsByName(Welcome_Page);
    } // setupUi

    void retranslateUi(QWidget *Welcome_Page)
    {
        Welcome_Page->setWindowTitle(QApplication::translate("Welcome_Page", "Form", 0));
        label->setText(QString());
        StartButton->setText(QApplication::translate("Welcome_Page", "Start plotting!", 0));
        StartButton->setShortcut(QApplication::translate("Welcome_Page", "Return", 0));
    } // retranslateUi

};

namespace Ui {
    class Welcome_Page: public Ui_Welcome_Page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_PAGE_H
