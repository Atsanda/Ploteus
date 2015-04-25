#include "ploteuswindow.h"
#include "ui_welcome_page.h"
#include "ui_table_chs_pg.h"
#include <QApplication>
#include "qcustomplot.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget Tabl_chs_pg;
    PloteusWindow w(Tabl_chs_pg);

    QPalette Pal;
    Pal.setColor(QPalette::Background, Qt::white);
    w.setAutoFillBackground(true);
    w.setPalette(Pal);

    QWidget Welcm_pg;
    Ui::Welcome_Page ui_1;
    ui_1.setupUi(&Welcm_pg);
    w.setCentralWidget(&Welcm_pg);

    Ui::Table_chs_pg ui_2;
    ui_2.setupUi(&Tabl_chs_pg);
    QObject::connect(ui_1.StartButton, SIGNAL(clicked()), &w, SLOT(turn_strtpage_to_tbl_chs_pg()) );

    QSplashScreen splash(QPixmap(":/window/splash.jpg"));

    splash.show();
    loadModules(&splash);
    splash.finish(&w);

    w.show();//Maximized();

    return a.exec();
}
