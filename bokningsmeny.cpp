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

    Databas databasobjekt;
    //Lägger in salar i sal_combobox
    QVector<QString> sallista = databasobjekt.sjukhus_select("salar");
    for(int i{0}; i < (sallista.length()/2); i++)
    {
        QString namn = sallista.at(i*2);
        QString spec = sallista.at((i*2)+1);
        ui->sal_comboBox->addItem(namn + " (" + spec + ")");
    }
    //Lägger in personal i pers_combobox
    QVector<QString> perslista = databasobjekt.sjukhus_select("personal");
    for(int i{0}; i < (perslista.length()/3); i++)
    {
        QString namn = perslista.at(i*3);
        QString enamn = perslista.at((i*3)+1);
        QString spec = perslista.at((i*3)+2);
        ui->pers_comboBox->addItem(namn + " " + enamn + " (" + spec + ")");
    }
    //Lägger in utrustning
    QVector<QString> utrlista = databasobjekt.sjukhus_select("utrustning");
    for(int i{0}; i < (utrlista.length()/2); i++)
    {
        QString namn = utrlista.at(i*2);
        QString spec = utrlista.at((i*2)+1);
        ui->utr_comboBox->addItem(namn + " (" + spec + ")");
    }
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

void bokningsmeny::on_sal_comboBox_currentTextChanged(const QString in_sal)
{
    Qsalnamn = in_sal;
}

void bokningsmeny::on_pers_comboBox_currentTextChanged(const QString in_pers)
{
    Qpersonalnamn = in_pers;
}

void bokningsmeny::on_utr_comboBox_currentTextChanged(const QString in_utr)
{
    Qutrustningnamn = in_utr;
}


void bokningsmeny::make_Bokning(std::string stdsalnamn,
                                std::string stdpersonalnamn,
                                std::string stdutrustningnamn,
                                double start_tid,
                                double slut_tid,
                                int dag)
{
    Bokning(stdsalnamn, stdpersonalnamn, stdutrustningnamn, start_tid, slut_tid, dag);
}

void bokningsmeny::on_pushButton_2_clicked()
{
    //Kontrollerar om sluttid > starttid. Annars ge fel
    if( (((slut_tid <= start_tid) || !minuter_check(start_tid)) || !minuter_check(slut_tid)) )
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Fel!","En Felinmatning har skett!");
        messageBox.setFixedSize(500,200);
    }
    else
    {
        stdsalnamn = Qsalnamn.toStdString();
        stdpersonalnamn = Qpersonalnamn.toStdString();
        stdutrustningnamn = Qutrustningnamn.toStdString();

        //BOKNINGSFUNKTION
        make_Bokning(stdsalnamn, stdpersonalnamn, stdutrustningnamn, start_tid, slut_tid, dag);

        this->close();
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

