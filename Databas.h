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

    QVector<QString> bokning_select(const QString Qobjekttyp,
                                    const QString Qobjektnamn,
                                    const QString Qstart_tid,
                                    const QString Qslut_tid,
                                    const QString Qdag);

    QVector<QString> sjukhus_select(const QString alternativ);

    QSqlDatabase db;
};

#endif
