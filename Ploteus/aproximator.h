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
#include "aproximation.h"
#include "file_reading.h"

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
    QString FILE_NAME;
    void borrow_data_from_created_tbl(PloteusWindow*);

};

#endif // APROXIMATOR

