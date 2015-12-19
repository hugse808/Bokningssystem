/* schema.h
 *
 * Beskrivning: Defintion av schema och dess funktioner.
 *
 * Författare: Hugo Severinsson
 *
 */

#ifndef SCHEMA_H
#define SCHEMA_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QString>
#include <stdio.h>
#include <math.h>

namespace Ui {
class schema;
}

class schema : public QMainWindow
{
    Q_OBJECT

public:
    //Konstruktor
    explicit schema(QWidget *parent = 0);
    ~schema();

private slots:
    //Medlemsfunktioner
    void on_pushButton_clicked();
    void on_comboBox_2_currentTextChanged(const QString vobjektnamn);
    void on_spinBox_valueChanged(int vdag);
    void on_doubleSpinBox_valueChanged(double vstart_tid);
    void on_doubleSpinBox_2_valueChanged(double vslut_tid);
    bool minuter_check(double val);

    void on_radioButton_3_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

private:
    //Datamedlemmar
    Ui::schema *ui;

    QStandardItemModel *schemat;

    QString Qobjekttyp{""};
    QString Qobjektnamn;
    std::string stdobjekttyp;
    std::string stdobjektnamn;
    int dag = 1;
    double start_tid{0.00};
    double slut_tid{0.00};
};

#endif // SCHEMA_H
