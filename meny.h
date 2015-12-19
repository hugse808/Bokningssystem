/*meny.h
 *
 * Beskrivning: Deklaration av meny och dess funktioner.
 *
 * Författare: Hugo Severinsson
 *
 */

#ifndef MENY
#define MENY

#include "bokningsmeny.h"
#include "avbokningsmeny.h"
#include "schema.h"
#include <QObject>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>

class meny : public QWidget
{
    Q_OBJECT
public:
    explicit meny(QWidget *parent = 0);

private slots:
    void skapa_bmeny();
    void skapa_avmeny();
    void skapa_smeny();
    void avsluta();

private:
    QPushButton *boka_knapp;
    QPushButton *avboka_knapp;
    QPushButton *schema_knapp;
    QPushButton *exit_knapp;

    bokningsmeny *bmeny;
    avbokningsmeny *avmeny;
    schema *smeny;
};

#endif // MENY

