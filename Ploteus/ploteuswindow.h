#ifndef PLOTEUSWINDOW_H
#define PLOTEUSWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QSplashScreen>
#include <iostream>
#include <QPixmap>
#include <QPalette>
#include <QMessageBox>
#include <vector>
#include <QDebug>
#include "qcustomplot.h"
#include "aproximator.h"

class Aproximator;

namespace Ui {
class Table_chs_pg;
class Welcome_Page;
class Create_table;
class Add_table;
class Plotting_page;
}

class PloteusWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PloteusWindow(QWidget *parent = 0);
    ~PloteusWindow();
    Aproximator *Aproximtr;
    QTableWidget* get_table();
    bool get_linerian_but_status();
    bool get_lagrange_but_status();

private:  
    QWidget *Tbl_chs_pg;
    QWidget *Welcm_pg;
    QWidget *Create_table;
    QWidget *Add_table;
    QWidget *Plotting_pg;
    Ui::Add_table *ui_add_table;
    Ui::Table_chs_pg *ui_tbl;
    Ui::Welcome_Page *ui_wel;
    Ui::Create_table *ui_create_table;
    Ui::Plotting_page *ui_plotting_page;

public slots:
    void turn_strtpage_to_tbl_chs_pg();
    void load_external_table();
    void create_table();
    void add_row_to_table(int , int);
    void turn_to_plotting_page_from_created_tbl();
    void turn_to_plotting_page_from_added_tbl();
    void add_table();
};



void loadModules(QSplashScreen* psplash);

#endif // PLOTEUSWINDOW_H
