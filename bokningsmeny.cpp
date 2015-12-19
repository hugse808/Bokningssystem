/*bokningsmeny.cpp
 *
 * Beskrivning: Definition av meny för bokningar och dess funktioner.
 *
 * Författare: Hugo Severinsson och Anton Lindman
 *
 */

#include "bokningsmeny.h"
#include "ui_bokningsmeny.h"
#include "Databas.h"
#include "bokning.h"
#include <QMessageBox>
#include <QDebug>
#include <QVector>

bokningsmeny::bokningsmeny(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bokningsmeny)
{
    ui->setupUi(this);

    setFixedSize(900,600);
    ui->spinBox->setMaximum(31);
    ui->spinBox->setMinimum(1);
    ui->doubleSpinBox->setMaximum(23.59);
    ui->doubleSpinBox_2->setMaximum(23.59);
}

bokningsmeny::~bokningsmeny()
{
    delete ui;
}

void bokningsmeny::on_doubleSpinBox_2_valueChanged(double in_starttid)
{
    start_tid = in_starttid;
}

void bokningsmeny::on_doubleSpinBox_valueChanged(double in_sluttid)
{
    slut_tid = in_sluttid;
}

void bokningsmeny::on_spinBox_valueChanged(int dag1)
{
    dag = dag1;
}

void bokningsmeny::on_comboBox_currentTextChanged(const QString vobjektnamn)
{
    Qobjektnamn = vobjektnamn;
}

void bokningsmeny::make_Bokning(std::string stdobjekttyp,
                        std::string stdobjektnamn,
                        double start_tid,
                        double slut_tid,
                        int dag)
{
    Bokning(stdobjekttyp, stdobjektnamn, start_tid, slut_tid, dag);
}

void bokningsmeny::on_pushButton_2_clicked()
{
    //Kontrollerar om sluttid > starttid. Annars ge fel
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

        //BOKNINGSFUNKTION
        make_Bokning(stdobjekttyp, stdobjektnamn, start_tid, slut_tid, dag);

        this->close();
    }
}

void bokningsmeny::on_radioButton_3_clicked()
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

void bokningsmeny::on_radioButton_2_clicked()
{
    ui->comboBox->clear();
    //Sätter Qobjekttyp till personal
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

void bokningsmeny::on_radioButton_clicked()
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

//Kontrollerar att minuter inte överstiger 59
bool bokningsmeny::minuter_check(double val)
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
