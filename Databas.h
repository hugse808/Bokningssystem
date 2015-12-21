/*
 * Databas.h
 *
 * BESKRIVNING:Klassen Databas. Sätter in, plockar bort
 * och raderar objekt i databasen.
 *
 * FÖRFATTARE: Marija Dahm, Alex Mourad
 */

#ifndef DATABAS_H
#define DATABAS_H

#include "Avbokning.h"
#include "Sjukhus.h"
#include "bokning.h"

#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <string>

using namespace std;

/*--------------DATABAS------------
*/

class Databas
{
public:

    //Defaultkonstruktor
    Databas() = default;
    ~Databas() = default;

    //Medlemsfunktioner
    void sjukhus_insert(const Sjukhus& objekt);
    void bokning_insert(const Bokning& objekt);
    void avbokning_delete(const Avbokning& objekt);

    QVector<QString> bokning_select(const QString salnamn,
                                         const QString personalnamn,
                                         const QString utrustningnamn
                                         const QString start_tid,
                                         const QString slut_tid,
                                         const QString dag);
                                         
    QVector<QString> allasal_select(const QString salnamn);
    
    QVector<QString> allabokning_select(const QString dag);

    QVector<QString> sjukhus_select(const QString alternativ);

    QSqlDatabase db;
};

#endif
