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

    Databas databasobjekt;
    //Lägger in salar i sal_combobox
    QVector<QString> sallista = databasobjekt.sjukhus_select("salar");
    for(int i{0}; i < (sallista.length()/2); i++)
    {
        QString namn = sallista.at(i*2);
        QString spec = sallista.at((i*2)+1);
        ui->comboBox->addItem(namn + " (" + spec + ")");
    }
}

avbokningsmeny::~avbokningsmeny()
{
    delete ui;
}

//Sätter salnamn till i boxen valt värdet
void avbokningsmeny::on_comboBox_currentTextChanged(const QString in_salnamn)
{
    Qsalnamn = in_salnamn;
}

//Sätter dag till, i boxen givet värde
void avbokningsmeny::on_spinBox_valueChanged(int dag1)
{
    dag = dag1;
}

//Sätter starttid till, i boxen givet värde
void avbokningsmeny::on_doubleSpinBox_valueChanged(double in_starttid)
{
    start_tid = in_starttid;
}

//Sätter sluttid till, i boxen givet värde
void avbokningsmeny::on_doubleSpinBox_2_valueChanged(double in_sluttid)
{
    slut_tid = in_sluttid;
}

//Anropar avbokningskonstruktorn
void avbokningsmeny::make_Avbokning(std::string stdsalnamn,
                                    double start_tid,
                                    double slut_tid,
                                    int dag)
{
    //avboknignskonstruktor
    Avbokning(stdsalnamn,
              start_tid,
              slut_tid,
              dag);
}

void avbokningsmeny::on_pushButton_clicked()
{
    //ta bort bokning
    if( (((slut_tid <= start_tid) || !minuter_check(start_tid)) || !minuter_check(slut_tid) ))
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Fel!","En Felinmatning har skett!");
        messageBox.setFixedSize(500,200);
    }
    else
    {
        stdsalnamn = Qsalnamn.toStdString();

        make_Avbokning(stdsalnamn,
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
