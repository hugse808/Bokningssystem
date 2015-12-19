/* schema.cpp
 *
 * Beskrivning: Defintion av schema och dess funktioner.
 *
 * Författare: Hugo Severinsson och Anton Lindman
 *
 */
#include "schema.h"
#include "Databas.h"
#include "ui_schema.h"

#include <QVector>
#include <QMessageBox>

schema::schema(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::schema)
{
    ui->setupUi(this);
    setFixedSize(900,600);

    ui->spinBox->setMaximum(31);
    ui->spinBox->setMinimum(1);
    ui->doubleSpinBox->setMaximum(23.59);
    ui->doubleSpinBox_2->setMaximum(23.59);
}

schema::~schema()
{
    delete ui;
}

void schema::on_comboBox_2_currentTextChanged(const QString vobjektnamn)
{
    Qobjektnamn = vobjektnamn;
}

void schema::on_spinBox_valueChanged(int vdag)
{
    dag = vdag;
}

void schema::on_doubleSpinBox_valueChanged(double vstart_tid)
{
    start_tid = vstart_tid;
}

void schema::on_doubleSpinBox_2_valueChanged(double vslut_tid)
{
    slut_tid = vslut_tid;
}

void schema::on_pushButton_clicked()
{
    if( (((slut_tid <= start_tid) || !minuter_check(start_tid)) || !minuter_check(slut_tid) ) || Qobjekttyp == "")
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Fel!","En Felinmatning har skett!");
        messageBox.setFixedSize(500,200);
    }
    else
    {
        QString Qstart_tid{QString::fromStdString(to_string(start_tid))};
        QString Qslut_tid{QString::fromStdString(to_string(slut_tid))};
        QString Qdag{QString::fromStdString(to_string(dag))};


        Databas databasobjekt;
        QVector<QString> schemalista =
                databasobjekt.bokning_select(Qobjekttyp, Qobjektnamn, Qstart_tid, Qslut_tid, Qdag);

        int c = 5;
        int r = 100; //Ändra värdet?

        //HÄMTA FRÅN DATABAS OCH SÄTT IN I KOLUMNER M. NEDANSTÅENDE KOMMANDON
        //Tex använda length för att sätta antal rader? c = query.length() ?
        //Sedan skapa en for/while loop för alla rader. ezpz

        schemat = new QStandardItemModel(r, c, this);

        schemat->setHorizontalHeaderItem(0,new QStandardItem(QString("Objekttyp")));
        schemat->setHorizontalHeaderItem(1,new QStandardItem(QString("Objektnamn")));
        schemat->setHorizontalHeaderItem(2,new QStandardItem(QString("Starttid")));
        schemat->setHorizontalHeaderItem(3,new QStandardItem(QString("Sluttid")));
        schemat->setHorizontalHeaderItem(4,new QStandardItem(QString("Dag")));

        for(int i{0}; i < (schemalista.length()/5); i++)
        {
            QString typ = schemalista.at(i*5);
            schemat->setItem(i,0,new QStandardItem(typ));
            QString namn = schemalista.at((i*5)+1);
            schemat->setItem(i,1,new QStandardItem(namn));
            QString starttid = schemalista.at((i*5)+2);
            schemat->setItem(i,2,new QStandardItem(starttid));
            QString sluttid = schemalista.at((i*5)+3);
            schemat->setItem(i,3,new QStandardItem(sluttid));
            QString dag = schemalista.at((i*5)+4);
            schemat->setItem(i,4,new QStandardItem(dag));
        }

        //Visar schemat för användaren
        ui->tableView->setModel(schemat);
    }
}

bool schema::minuter_check(double val)
{

    double int_del, deci_del = modf(val, &int_del);

    if(deci_del < 0.60)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void schema::on_radioButton_3_clicked()
{
    ui->comboBox_2->clear();
    //Sätter Qobjekttyp till personal
    Qobjekttyp = "personal";

    Databas databasobjekt;
    QVector<QString> namnlista = databasobjekt.sjukhus_select("personal");

    //Lägger in i combobox...
    for(int i{0}; i < namnlista.length(); i++)
    {
        QString name = namnlista.at(i);
        ui->comboBox_2->addItem(name);
    }
}

void schema::on_radioButton_2_clicked()
{
    ui->comboBox_2->clear();
    //Sätter Qobjekttyp till personal
    Qobjekttyp = "salar";

    Databas databasobjekt;
    QVector<QString> namnlista = databasobjekt.sjukhus_select("salar");

    //Lägger in i combobox...
    for(int i{0}; i < namnlista.length(); i++)
    {
        QString name = namnlista.at(i);
        ui->comboBox_2->addItem(name);
    }
}

void schema::on_radioButton_clicked()
{
    ui->comboBox_2->clear();
    Qobjekttyp = "utrustning";
    Databas databasobjekt;
    QVector<QString> namnlista = databasobjekt.sjukhus_select("utrustning");

    //Lägger in i combobox...
    for(int i{0}; i < namnlista.length(); i++)
    {
        QString name = namnlista.at(i);
        ui->comboBox_2->addItem(name);
    }
}
