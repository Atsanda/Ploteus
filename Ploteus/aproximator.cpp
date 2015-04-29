#include "ploteuswindow.h"
#include "ui_welcome_page.h"
#include "ui_table_chs_pg.h"
#include "ui_create_table.h"
#include "aproximator.h"

Aproximator::Aproximator():
    QObject(0){}

void Aproximator::borrow_data_from_created_tbl(PloteusWindow* pl_win)
{
    QTableWidget *table = pl_win->get_table();
    QTableWidgetItem* node;
    float tmp;
    bool ok;
    int i,j;
    for(i=0; i < table->rowCount(); i++)
    {
        node = table->item(i,0);

        if( node == NULL )
            break;

        if( node->text().contains(',') )
        {
            node->text().replace(',',".");
        }

        tmp = node->text().toFloat(&ok);

        if(!ok)
            throw QString("Invalid format");

        input_x.push_back(tmp);
    }

    for(j=0; j < table->rowCount(); j++)
    {
        node = table->item(j,1);

        if( node == NULL )
            break;

        if( node->text().contains(',') )
        {
            node->text().replace(',',".");
        }

        tmp = node->text().toFloat(&ok);

        if(!ok)
            throw QString("Invalid format");

        input_y.push_back(tmp);
    }

    if( i != j )
        throw QString("Invalid format");
}
