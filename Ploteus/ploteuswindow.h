#ifndef PLOTEUSWINDOW_H
#define PLOTEUSWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QSplashScreen>
#include <iostream>
#include <QPixmap>

namespace Ui {
class PloteusWindow;
}

class PloteusWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PloteusWindow(QWidget *parent = 0);
    ~PloteusWindow();

private:
    Ui::PloteusWindow *ui;
};

void loadModules(QSplashScreen* psplash);

#endif // PLOTEUSWINDOW_H
