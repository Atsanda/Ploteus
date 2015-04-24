#include "ploteuswindow.h"
#include "ui_ploteuswindow.h"

PloteusWindow::PloteusWindow(QWidget &tbl_page, QWidget *parent) :
    QMainWindow(parent), tbl_shc_pg(tbl_page)
    //ui(new Ui::PloteusWindow)
{
    //ui->setupUi(this);
    setWindowIcon(QIcon(":/window/icon.png"));
}

PloteusWindow::~PloteusWindow()
{
    //delete ui;
}

PloteusWindow::turn_strtpage_to_tbl_chs_pg()
{
    setCentralWidget(&tbl_shc_pg);
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
                         Qt::blue);
    }
}
