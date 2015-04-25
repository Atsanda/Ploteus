#ifndef PLOTEUSWINDOW_H
#define PLOTEUSWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QSplashScreen>
#include <iostream>
#include <QPixmap>
#include <QPalette>
#include "qcustomplot.h"


namespace Ui {
class Table_chs_pg;
class Welcome_Page;
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
    Ui::Table_chs_pg *ui_tbl;
    Ui::Welcome_Page *ui_wel;
public slots:
    void turn_strtpage_to_tbl_chs_pg();
};


void loadModules(QSplashScreen* psplash);

#endif // PLOTEUSWINDOW_H
