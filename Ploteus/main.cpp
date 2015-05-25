#include "ploteuswindow.h"
#include <QApplication>
#include "qcustomplot.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PloteusWindow w;

    QSplashScreen splash(QPixmap(":/window/splash.jpg"));

    splash.show();
    loadModules(&splash);
    splash.finish(&w);

    w.show();

    return a.exec();
}
