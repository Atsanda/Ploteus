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
    Create_table(new QWidget),
    Aproximtr(new Aproximator)
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
    QObject::connect(ui_create_table->Aproximate_button, SIGNAL(clicked()), this, SLOT(turn_to_plotting_page()));

}

PloteusWindow::~PloteusWindow()
{
    delete ui_tbl;
    delete ui_wel;
    delete ui_create_table;
    delete Tbl_chs_pg;
    delete Welcm_pg;
    delete Create_table;
    delete Aproximtr;
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
    ui_create_table->tableWidget->setRowCount(10);
    ui_create_table->tableWidget->setColumnCount(2);
    QStringList Headers;
    Headers<<"X axis"<<"Y axis";
    ui_create_table->tableWidget->setHorizontalHeaderLabels(Headers);

    QObject::connect(ui_create_table->tableWidget,
                     SIGNAL(cellChanged(int ,int)),
                     this,
                     SLOT(add_row_to_table(int, int)));

    setCentralWidget(Create_table);
}

void PloteusWindow::add_row_to_table(int row, int)
{
    if(row == ui_create_table->tableWidget->rowCount()- 1)
        ui_create_table->tableWidget->insertRow(row+1);

}

void PloteusWindow::turn_to_plotting_page()
{
    try{
        Aproximtr->borrow_data_from_created_tbl(this);
    }catch(QString err_msg){
        QMessageBox::warning(this,
                                     "Warning",
                                     err_msg
                                    );
        return;
    }
}

QTableWidget* PloteusWindow::get_table()
{
    return (this->ui_create_table->tableWidget);
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



