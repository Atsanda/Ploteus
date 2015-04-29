#ifndef APROXIMATOR
#define APROXIMATOR

#include <QMainWindow>
#include <QtGui>
#include <QSplashScreen>
#include <iostream>
#include <QPixmap>
#include <QPalette>
#include <QMessageBox>
#include <vector>
#include <QDebug>
#include "ploteuswindow.h"

class PloteusWindow;


class Aproximator : QObject
{
    Q_OBJECT

public:
    Aproximator();
    ~Aproximator(){};

    std::vector<float> input_x;
    std::vector<float> input_y;
    void borrow_data_from_created_tbl(PloteusWindow*);

};

#endif // APROXIMATOR

