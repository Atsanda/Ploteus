#include "ploteuswindow.h"
#include "ui_welcome_page.h"
#include "ui_table_chs_pg.h"
#include "ui_create_table.h"
#include "ui_add_table.h"
#include "ui_plotting.h"
#include "file_reading.h"
#include "aproximation.h"
#include <QFileDialog>

PloteusWindow::PloteusWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_tbl(new Ui::Table_chs_pg),
    ui_wel(new Ui::Welcome_Page),
    ui_create_table(new Ui::Create_table),
    ui_add_table(new Ui::Add_table),
    ui_plotting_page(new Ui::Plotting_page),
    Plotting_pg(new QWidget),
    Add_table(new QWidget),
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

    ui_add_table->setupUi(Add_table);

    ui_plotting_page->setupUi(Plotting_pg);

    QObject::connect(ui_wel->StartButton, SIGNAL(clicked()), this, SLOT(turn_strtpage_to_tbl_chs_pg()) );
    QObject::connect(ui_tbl->Add_tbl, SIGNAL(clicked()), this, SLOT(add_table()));
    QObject::connect(ui_tbl->Create_table, SIGNAL(clicked()), this, SLOT(create_table()));
    QObject::connect(ui_create_table->Aproximate_button, SIGNAL(clicked()), this, SLOT(turn_to_plotting_page_from_created_tbl()));
    QObject::connect(ui_add_table->Choose_file, SIGNAL(clicked()), this, SLOT(load_external_table()));
    QObject::connect(ui_add_table->Start_aproximate, SIGNAL(clicked()), this, SLOT(turn_to_plotting_page_from_added_tbl()));
    QObject::connect(ui_plotting_page->Save_as_pdf, SIGNAL(clicked()), this, SLOT(save_as_pdf()));

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

    Aproximtr->FILE_NAME = str;

    if (str.isEmpty()){
        return;
    }

    ui_add_table->File_Path->setText(str);
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

void PloteusWindow::turn_to_plotting_page_from_created_tbl()
{
    try{
        Aproximtr->borrow_data_from_created_tbl(this);
    }catch(QString err_msg){
        QMessageBox::warning(this,
                                     "Warning",
                                     err_msg
                                    );
        Aproximtr->input_x.clear();
        Aproximtr->input_y.clear();
        return;
    }

    setCentralWidget(Plotting_pg);
    setNewGraph(Aproximtr);
}

void PloteusWindow::turn_to_plotting_page_from_added_tbl()
{
    const char* constchar_FIlE_NAME = Aproximtr->FILE_NAME.toStdString().c_str();
    cout << constchar_FIlE_NAME << endl;
    int coord_count = 0;
    open_file_and_parse(constchar_FIlE_NAME, Aproximtr->input_x, Aproximtr->input_y, coord_count);

        if(get_linerian_but_status_for_add_table())
        {
            Aproximtr->aprx_type = LINEAR;
            cout << "User chose linear aproximation" << endl;
        } else if (get_lagrange_but_status_for_add_table())
        {
            Aproximtr->aprx_type = LAGRANGE;
            cout << "User chose lagrange aproximation" << endl;
        }
    setCentralWidget(Plotting_pg);
    setNewGraph(Aproximtr);

}

void PloteusWindow::setNewGraph(Aproximator *Aproximtr)
{
    int n = Aproximtr->input_x.size();
    lagrange_points lagrange_points;
    QVector<double> X;
    QVector<double> Y;

    float min_x = 0.0, min_y = 0.0;
    float max_x = 0.0, max_y = 0.0;

    float min_xa = 0.0, min_ya = 0.0;
    float max_xa = 0.0, max_ya = 0.0;

    for(int i = 0; i < n; i++)
    {
        X.push_back(Aproximtr->input_x[i]);
        cout << X[i] << endl;
        Y.push_back(Aproximtr->input_y[i]);
        cout << Y[i] << endl;
    }

    min_x = *std::min_element (X.begin(), X.end());
    min_y = *std::min_element (Y.begin(), Y.end());
    max_x = *std::max_element (X.begin(), X.end());
    max_y = *std::max_element (Y.begin(), Y.end());

    cout << "find elems" << endl;

    cout << min_x << " " << min_y << " " << max_x << " " << max_y << endl;

    QVector<double> Xa;
    QVector<double> Ya;

    if(Aproximtr->aprx_type == LAGRANGE){
        lagrange_points = lagrange_poly_aproximation(Aproximtr->input_x, Aproximtr->input_y, 20);
        for(int i = 0; i < lagrange_points.x_coordinates.size(); i++)
        {
            Xa.push_back(lagrange_points.x_coordinates[i]);
            Ya.push_back(lagrange_points.y_coordinates[i]);
        }
    } else if (Aproximtr->aprx_type == LINEAR)
    {
        QVector<float> coef_of_linear_aproximation = linear_aproximation(Aproximtr->input_x, Aproximtr->input_y);
        float DELTA = 0.1;
        for(min_x; min_x < max_x ; min_x+=DELTA)
        {
            Xa.push_back(min_x);
            Ya.push_back(coef_of_linear_aproximation[0]*min_x + coef_of_linear_aproximation[1]);
        }
    }

    min_xa = *std::min_element (Xa.begin(), Xa.end());
    min_ya = *std::min_element (Ya.begin(), Ya.end());
    max_xa = *std::max_element (Xa.begin(), Xa.end());
    max_ya = *std::max_element (Ya.begin(), Ya.end());


     ui_plotting_page->Plotting_zone->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                      QCP::iSelectLegend | QCP::iSelectPlottables);

    ui_plotting_page->Plotting_zone->addGraph();
    ui_plotting_page->Plotting_zone->graph(0)->setData(Xa, Ya);
    ui_plotting_page->Plotting_zone->graph(0)->setPen(QPen(Qt::red));
    ui_plotting_page->Plotting_zone->graph(0)->setBrush(QBrush(QColor(255, 0, 0, 0)));

    ui_plotting_page->Plotting_zone->addGraph();
    ui_plotting_page->Plotting_zone->graph(1)->setData(X, Y);
    ui_plotting_page->Plotting_zone->graph(1)->setPen(QPen(Qt::blue));
    ui_plotting_page->Plotting_zone->graph(1)->setBrush(QBrush(QColor(0, 0, 255, 0)));

    ui_plotting_page->Plotting_zone->plotLayout()->insertRow(0);
    ui_plotting_page->Plotting_zone->plotLayout()->addElement(0, 0, new QCPPlotTitle(ui_plotting_page->Plotting_zone, "Plots"));
    ui_plotting_page->Plotting_zone->legend->setVisible(true);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui_plotting_page->Plotting_zone->setFont(legendFont);
    ui_plotting_page->Plotting_zone->legend->setSelectedFont(legendFont);
    ui_plotting_page->Plotting_zone->legend->setSelectableParts(QCPLegend::spItems);


    ui_plotting_page->Plotting_zone->xAxis->setLabel("x");
    ui_plotting_page->Plotting_zone->yAxis->setLabel("y");

    ui_plotting_page->Plotting_zone->xAxis->setRange(min_xa-5.0, max_xa+5);
    ui_plotting_page->Plotting_zone->yAxis->setRange(min_ya-5.0, max_ya+5.0);
    ui_plotting_page->Plotting_zone->replot();


}

void PloteusWindow::save_as_pdf()
{
    QString str =
            QFileDialog::getSaveFileName(0,
                                         "Save as PDF",
                                         "/home/untitled.pdf",
                                         "*.pdf");
    if (!str.isEmpty())
    {
        if(!ui_plotting_page->Plotting_zone->savePdf(str))
            QMessageBox::warning(this,
                                         "Warning",
                                         "Can not be saved."
                                        );
    }
}


void PloteusWindow::add_table()
{
     setCentralWidget(Add_table);
}

QTableWidget* PloteusWindow::get_table()
{
    return (this->ui_create_table->tableWidget);
}

bool PloteusWindow::get_linerian_but_status_for_create_table()
{
    return this->ui_create_table->linear->isChecked();
}

bool PloteusWindow::get_lagrange_but_status_for_create_table()
{
    return this->ui_create_table->lagrange->isChecked();
}

bool PloteusWindow::get_linerian_but_status_for_add_table()
{
    return this->ui_add_table->linear->isChecked();
}

bool PloteusWindow::get_lagrange_but_status_for_add_table()
{
    return this->ui_add_table->lagrange->isChecked();
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



