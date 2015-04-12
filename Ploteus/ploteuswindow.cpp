#include "ploteuswindow.h"
#include "ui_ploteuswindow.h"

PloteusWindow::PloteusWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PloteusWindow)
{
    ui->setupUi(this);
}

PloteusWindow::~PloteusWindow()
{
    delete ui;
}

void loadModules(QSplashScreen* psplash)
{
    QTime time;
    time.start();

    for(int i = 0; i < 100; ){
        if (time.elapsed() > 40) {
            time.start();
            ++i;
        }

    psplash->showMessage("Loading modules: "
                         + QString::number(i) + "%",
                         Qt::AlignHCenter | Qt::AlignBottom,
                         Qt::black);
    }
}
