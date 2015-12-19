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
    void on_radioButton_3_toggled();
    void on_radioButton_2_toggled();
    void on_radioButton_toggled();
    void on_spinBox_valueChanged(int vdag);
    void on_pushButton_clicked();
    void on_doubleSpinBox_valueChanged(double vstart_tid);
    void on_doubleSpinBox_2_valueChanged(double vslut_tid);
    void make_Avbokning(std::string stdobjekttyp,
                        std::string stdobjektnamn,
                        double start_tid,
                        double slut_tid,
                        int dag);
    bool minuter_check(double val);
    void on_comboBox_currentTextChanged(const QString vobjektnamn);

private:
    //Datamedlemmar
    Ui::avbokningsmeny *ui;

    QString Qobjekttyp{""};
    QString Qobjektnamn;
    std::string stdobjekttyp;
    std::string stdobjektnamn;
    double start_tid{00.00};
    double slut_tid{00.00};
    int dag{1};
};

#endif // AVBOKNINGSMENY_H
