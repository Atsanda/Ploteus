#ifndef PLOTEUSWINDOW_H
#define PLOTEUSWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QSplashScreen>
#include <iostream>
#include <QPixmap>
#include <QPalette>
#include <QMessageBox>
#include "qcustomplot.h"


namespace Ui {
class Table_chs_pg;
class Welcome_Page;
class Create_table;
}

class PloteusWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PloteusWindow(QWidget *parent = 0);
    ~PloteusWindow();

private:
    QWidget *Tbl_chs_pg;
    QWidget *Welcm_pg;
    QWidget *Create_table;
    Ui::Table_chs_pg *ui_tbl;
    Ui::Welcome_Page *ui_wel;
    Ui::Create_table *ui_create_table;
public slots:
    void turn_strtpage_to_tbl_chs_pg();
    void load_external_table();
    void create_table();
};

/*class MyTablewidget : public QTableWidget
{
    Q_OBJECT

public:
    explicit MyTablewidget(QWidget *parent = 0);
    ~MyTablewidget();

};*/


void loadModules(QSplashScreen* psplash);

#endif // PLOTEUSWINDOW_H
