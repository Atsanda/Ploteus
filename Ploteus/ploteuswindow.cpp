#include "ploteuswindow.h"
#include "ui_welcome_page.h"
#include "ui_table_chs_pg.h"
#include "ui_create_table.h"

PloteusWindow::PloteusWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_tbl(new Ui::Table_chs_pg),
    ui_wel(new Ui::Welcome_Page),
    Tbl_chs_pg(new QWidget),
    Welcm_pg(new QWidget),
    Create_table(new QWidget)
{
    setWindowIcon(QIcon(":/window/icon.png"));

    QPalette Pal;
    Pal.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(Pal);

    ui_wel->setupUi(Welcm_pg);
    this->setCentralWidget(Welcm_pg);

    ui_tbl->setupUi(Tbl_chs_pg);

    ui_create_table->setupUi(Create_table);

    QObject::connect(ui_wel->StartButton, SIGNAL(clicked()), this, SLOT(turn_strtpage_to_tbl_chs_pg()) );
    QObject::connect(ui_tbl->Add_tbl, SIGNAL(clicked()), this, SLOT(load_external_table()));
    QObject::connect(ui_tbl->Create_table, SIGNAL(clicked()), this, SLOT(create_table()));

}

PloteusWindow::~PloteusWindow()
{
    delete ui_tbl;
    delete ui_wel;
    delete ui_create_table;
    delete Tbl_chs_pg;
    delete Welcm_pg;
    delete Create_table;
}

void PloteusWindow::turn_strtpage_to_tbl_chs_pg()
{
    setCentralWidget(Tbl_chs_pg);
}

void PloteusWindow::load_external_table()
{
    QString str = QFileDialog::getOpenFileName(this,
                                               QString::fromUtf8("Открыть файл"),
                                               QDir::homePath(),
                                               "Images (*.txt);;All files (*.*)");
    if (str.isEmpty()){
        return;
    }
}

void PloteusWindow::create_table()
{
    /*QStandardItemModel *model = new QStandardItemModel(5,2,this);
    ui_create_table->tableView->setModel(model);

    model->setHorizontalHeaderItem(0, new QStandardItem(QString("X axis")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Y axis")));*/

    ui_create_table->tableWidget->setRowCount(5);
    ui_create_table->tableWidget->setColumnCount(2);
    QObject::connect(ui_create_table->tableWidget,
                     SIGNAL(cellChanged(int row,int coloumn)),
                     ui_create_table->tableWidget,
                     SLOT(insertRow(int row)));

    setCentralWidget(Create_table);
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



