/*Avbokningsmeny.cpp
 *
 * Beskrivning: Definition av meny för avbokningar och dess funktioner.
 *
 * Författare: Hugo Severinsson och Anton Lindman
 *
 */

#include "avbokningsmeny.h"
#include "ui_avbokningsmeny.h"
#include "Databas.h"
#include "Avbokning.h"
#include <QMessageBox>
#include <QVector>

avbokningsmeny::avbokningsmeny(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::avbokningsmeny)
{
    ui->setupUi(this);
    setFixedSize(900,600);

    ui->doubleSpinBox->setMaximum(23.59);
    ui->doubleSpinBox_2->setMaximum(23.59);
    ui->spinBox->setMaximum(31);
    ui->spinBox->setMinimum(1);
}

avbokningsmeny::~avbokningsmeny()
{
    delete ui;
}

//Sätter personal till, i boxen givet värde och lägger till namn i comboboxen
void avbokningsmeny::on_radioButton_2_toggled()
{
    ui->comboBox->clear();
    //Sätter Qobjekttyp till personal
    Qobjekttyp = "personal";

    Databas databasobjekt;
    QVector<QString> namnlista = databasobjekt.sjukhus_select("personal");

    //Lägger in i combobox...
    for(int i{0}; i < namnlista.length(); i++)
    {
        QString name = namnlista.at(i);
        ui->comboBox->addItem(name);
    }
}

//Sätter sal till, i boxen givet värde och lägger till namn i comboboxen
void avbokningsmeny::on_radioButton_3_toggled()
{
    ui->comboBox->clear();
    Qobjekttyp = "salar";

    Databas databasobjekt;
    QVector<QString> namnlista = databasobjekt.sjukhus_select("salar");

    //Lägger in i combobox...
    for(int i{0}; i < namnlista.length(); i++)
    {
        QString name = namnlista.at(i);
        ui->comboBox->addItem(name);
    }
}

//Sätter utrustning till, i boxen givet värde och lägger till namn i comboboxen
void avbokningsmeny::on_radioButton_toggled()
{
    ui->comboBox->clear();
    Qobjekttyp = "utrustning";
    Databas databasobjekt;
    QVector<QString> namnlista = databasobjekt.sjukhus_select("utrustning");

    //Lägger in i combobox...
    for(int i{0}; i < namnlista.length(); i++)
    {
        QString name = namnlista.at(i);
        ui->comboBox->addItem(name);
    }
}

//Sätter dag till, i boxen givet värde
void avbokningsmeny::on_spinBox_valueChanged(int vdag)
{
    dag = vdag;
}

//Sätter starttid till, i boxen givet värde
void avbokningsmeny::on_doubleSpinBox_valueChanged(double vstart_tid)
{
    start_tid = vstart_tid;
}

//Sätter sluttid till, i boxen givet värde
void avbokningsmeny::on_doubleSpinBox_2_valueChanged(double vslut_tid)
{
    slut_tid = vslut_tid;
}

//Anropar avbokningskonstruktorn
void avbokningsmeny::make_Avbokning(std::string stdobjekttyp,
                                  std::string stdobjektnamn,
                                  double start_tid,
                                  double slut_tid,
                                  int dag)
{
    //avboknignskonstruktor
    Avbokning(stdobjekttyp, stdobjektnamn, start_tid, slut_tid, dag);
}

void avbokningsmeny::on_pushButton_clicked()
{
    //ta bort bokning
    if( (((slut_tid <= start_tid) || !minuter_check(start_tid)) || !minuter_check(slut_tid) ) || Qobjekttyp == "")
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Fel!","En Felinmatning har skett!");
        messageBox.setFixedSize(500,200);
    }
    else
    {
        stdobjekttyp = Qobjekttyp.toStdString();
        stdobjektnamn = Qobjektnamn.toStdString();

        make_Avbokning(stdobjekttyp,
                       stdobjektnamn,
                       start_tid,
                       slut_tid,
                       dag);

        this->close();
    }
}


bool avbokningsmeny::minuter_check(double val)
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


void avbokningsmeny::on_comboBox_currentTextChanged(const QString vobjektnamn)
{
    Qobjektnamn = vobjektnamn;
}
