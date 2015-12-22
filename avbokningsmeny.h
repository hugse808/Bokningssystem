/*Avbokningsmeny.h
 *
 * Beskrivning: Deklaration av meny för avbokningar och dess funktioner.
 *
 * Författare: Hugo Severinsson och Anton Lindman
 *
 */

#ifndef AVBOKNINGSMENY_H
#define AVBOKNINGSMENY_H

#include <QMainWindow>
#include <QString>
#include <string>
#include <stdio.h>
#include <math.h>


namespace Ui {
class avbokningsmeny;
}

class avbokningsmeny : public QMainWindow
{
    Q_OBJECT

public:
    //konstruktor
    explicit avbokningsmeny(QWidget *parent = 0);
    ~avbokningsmeny();

private slots:
//Medlemsfunktioner
    void on_comboBox_currentTextChanged(const QString in_salnamn);
    void on_spinBox_valueChanged(int dag1);
    void on_pushButton_clicked();
    void on_doubleSpinBox_valueChanged(double in_starttid);
    void on_doubleSpinBox_2_valueChanged(double in_sluttid);
    void make_Avbokning(std::string stdsalnamn,
                        std::string stdpersonalnamn,
                        std::string stdutrustningnamn,
                        double start_tid,
                        double slut_tid,
                        int dag);
    bool minuter_check(double val);


private:
    //Datamedlemmar
    Ui::avbokningsmeny *ui;

    QString Qsalnamn{""};
    QString Qpersonalnamn{""};
    QString Qutrustningnamn{""};
    std::string stdsalnamn;
    std::string stdpersonalnamn;
    std::string stdutrustningnamn;
    double start_tid{00.00};
    double slut_tid{00.00};
    int dag{1};
};

#endif // AVBOKNINGSMENY_H
