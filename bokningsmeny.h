/*bokningsmeny.h
 *
 * Beskrivning: Definition av en bokning och dess funktioner.
 *
 * Författare: Hugo Severinsson och Anton Lindman
 *
 */

#ifndef BOKNINGSMENY_H
#define BOKNINGSMENY_H


#include <QMainWindow>
#include <QString>
#include <string>
#include <stdio.h>
#include <math.h>

namespace Ui {
class bokningsmeny;
}

class bokningsmeny : public QMainWindow
{
    Q_OBJECT

public:
    //Konstruktor
    explicit bokningsmeny(QWidget *parent = 0);
    ~bokningsmeny();

private slots:
    //Medlemsfunktioner
    void on_doubleSpinBox_2_valueChanged(double in_starttid);
    void on_doubleSpinBox_valueChanged(double in_sluttid);
    void on_spinBox_valueChanged(int dag1);
    void on_pushButton_2_clicked();
    void on_sal_comboBox_currentTextChanged(const QString in_sal);
    void on_pers_comboBox_currentTextChanged(const QString in_pers);
    void on_utr_comboBox_currentTextChanged(const QString in_utr);
    void make_Bokning(std::string stdsalnamn,
                      std::string stdpersonalnamn,
                      std::string stdutrustningnamn,
                      double start_tid,
                      double slut_tid,
                      int dag);
    bool minuter_check(double val);



private:
    //Datamedlemmar
    Ui::bokningsmeny *ui;

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

#endif // BOKNINGSMENY_H
