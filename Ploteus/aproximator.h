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

//--------types of aproximation
#define LINEAR 1
#define LAGRANGE 2
//-----------------------------

class PloteusWindow;


class Aproximator : QObject
{
    Q_OBJECT

public:
    Aproximator();
    ~Aproximator(){};

    int aprx_type;
    std::vector<float> input_x;
    std::vector<float> input_y;
    void borrow_data_from_created_tbl(PloteusWindow*);

};

#endif // APROXIMATOR

