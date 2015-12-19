/*
 * Databas.cc
 *
 * BESKRIVNING: Klassen Databas. Sätter in, plockar bort
 * och raderar objekt i databasen.
 *
 * FÖRFATTARE: Marija Dahm, Alex Mourad
 */

#include "Databas.h"
#include <iostream>
#include <QDebug>
#include <QVector>
#include <QMessageBox>
using namespace std;


/*-----DATABAS: Medlemsfunktioner---
*/

/*-----------Sjukhus_insert---------
 *Omvandlar Sjukhusobjekt till string.
 *Sätter in i rätt table*/

void Databas::sjukhus_insert(const Sjukhus& objekt)
{
    QString typ{QString::fromStdString(objekt.get_typ())};
    QString namn{QString::fromStdString(objekt.get_namn())};
    QString efternamn{QString::fromStdString(objekt.get_efternamn())};
    QString specialitet{QString::fromStdString(objekt.get_specialitet())};
    QString kapacitet{QString::fromStdString(to_string(objekt.get_kapacitet()))};
    QString text{""};

    bool check = false;

    if (typ == "Personal")
    { 
        text =
            "('" + typ + "', '" +
            namn + "', '" +
            efternamn + "', '" +
            specialitet + "')";

        {
        QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("Databas");
        mydb.open();

        QSqlQuery query;
        query.prepare( "INSERT INTO personal VALUES " + text );

        if(query.exec())
        {
            check = false;
        }
        else
        {
            qDebug() << "kunde inte sätta in i personal"
                        << query.lastError();
        }

        }

        QSqlDatabase::removeDatabase("qt_sql_default_connection");

    }
    else if (typ == "Salar")
    { 
        text = 
            "('" + typ + "', '" +
            namn + "', '" +
            specialitet + "', '" +
            kapacitet + "')";

        {

        QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("Databas");
        mydb.open();


        QSqlQuery query;
        query.prepare( "INSERT INTO salar VALUES" + text);

        if(query.exec())
        {
           check = true;
        }
        else
        {
            qDebug() << "kunde inte sätta in i salar"
                        <<query.lastError();
        }

        }

        QSqlDatabase::removeDatabase("qt_sql_default_connection");
    }
    else
    { 
        text = 
            "('" + typ + "', '" +
            namn + "', '" +
            specialitet + "')";
    {

     QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
     mydb.setDatabaseName("Databas");
     mydb.open();

     QSqlQuery query;
     query.prepare( "INSERT INTO utrustning VALUES" + text);

     if(query.exec())
      {
          check = true;
      }
      else
      {
          qDebug() << "Kunder inte sätta in i utrustning"
                      <<query.lastError();
      }
   }

  QSqlDatabase::removeDatabase("qt_sql_default_connection");


}
return;
}


/*-----Boknings_insert-------
 *Omvandlar Bokningsobjekt till string.
 *Sätter in i databasen i table bokning*/
void Databas::bokning_insert (const Bokning& objekt)
{
    QString typ{QString::fromStdString(objekt.get_typ())};
    QString objektnamn{QString::fromStdString(objekt.get_objektnamn())};
    QString start_tid{QString::fromStdString(to_string(objekt.get_start_tid()))};
    QString slut_tid{QString::fromStdString(to_string(objekt.get_slut_tid()))};
    QString dag{QString::fromStdString(to_string(objekt.get_dag()))};
    QString text{""};
    {
        text = "('" +  typ + "', '"
                + objektnamn + "', '"
                + start_tid + "', '"
                + slut_tid + "', '"
                + dag + "')";
        {
            bool check = false;

            QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
            mydb.setDatabaseName("Databas");
            mydb.open();

            QSqlQuery query;/*
            query.prepare("SELECT FROM bokning WHERE typ AND objektnamn AND start_tid AND slut_tid AND dag");
            query.bindValue(":typ", "'"+typ+"'");
            query.bindValue(":objektnamn", "'"+objektnamn+"'");
            query.bindValue(":start_tid", "'"+start_tid+"'");
            query.bindValue(":slut_tid", "'"+slut_tid+"'");
            query.bindValue(":dag", "'"+dag+"'");

            if(query.exec())
            {
                QMessageBox messageBox;
                messageBox.critical(0,"Fel!","Bokningen finns redan!");
                messageBox.setFixedSize(500,200);
            }
            else
            {*/
                query.prepare("INSERT INTO bokning VALUES" + text);
                if(query.exec())
                {
                    check = true;
                }
                else
                {
                    qDebug() << "Kunde inte sätta in i bokning"
                            <<query.lastError();
                }
            }
        //}

         QSqlDatabase::removeDatabase("qt_sql_default_connection");
    }
    return;
}


/*-----Avbokning_delete-------
 *Omvandlar Avbokningsobjekt till string.
 *Raderar dem från databasen*/
void Databas::avbokning_delete(const Avbokning& objekt)
{
    QString typ{QString::fromStdString(objekt.get_typ())};
    QString objektnamn{QString::fromStdString(objekt.get_objektnamn())};
    QString start_tid{QString::fromStdString(to_string(objekt.get_start_tid()))};
    QString slut_tid{QString::fromStdString(to_string(objekt.get_slut_tid()))};
    QString dag{QString::fromStdString(to_string(objekt.get_dag()))};

    {
        {
            QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
            mydb.setDatabaseName("Databas");
            mydb.open();


QSqlQuery query;
          query.prepare("SELECT * FROM bokning WHERE typ = '"+typ+"' AND objektnamn = '"+objektnamn+"' AND start_tid = '"+start_tid+"' AND slut_tid = '"+slut_tid+"' AND dag = '"+dag+"'");
         // query.prepare("SELECT column1, column2, column4, column3, column5 FROM bokning WHERE [typ = '"+typ+"'] AND [objektnamn = '"+objektnamn+"'] AND [start_tid = '"+start_tid+"'] AND [slut_tid = '"+slut_tid+"'] AND [dag = '"+dag+"']");
/*
query.prepare("SELECT typ AND objektnamn AND start_tid AND slut_tid AND dag FROM bokning");
query.bindValue(":typ", "'"+typ+"'");
query.bindValue(":objektnamn", "'"+objektnamn+"'");
query.bindValue(":start_tid", "'"+start_tid+"'");
query.bindValue(":slut_tid", "'"+slut_tid+"'");
query.bindValue(":dag", "'"+dag+"'");*/

            if(query.exec())
            {
                QSqlQuery queryDelete;
                //queryDelete.prepare("DELETE FROM bokning");
                queryDelete.prepare("DELETE FROM bokning WHERE typ = '"+typ+"' AND objektnamn = '"+objektnamn+"' AND start_tid = '"+start_tid+"' AND slut_tid = '"+slut_tid+"' AND dag = '"+dag+"'");

                bool tabort = queryDelete.exec();
                if(!tabort)
                {
                    qDebug() << queryDelete.lastError();
                }
            }
            else
            {
                QMessageBox messageBox;
                messageBox.critical(0,"Fel!","Fel! Bokningen finns inte");
                messageBox.setFixedSize(500,200);
            }

        }
        QSqlDatabase::removeDatabase("qt_sql_default_connection");
    }
    return;
}



/*-----Boknings_select-------
 *Plockar ut från table bokningar till Schema
 */

QVector<QString> Databas::bokning_select(const QString Qobjekttyp,
                                         const QString Qobjektnamn,
                                         const QString Qstart_tid,
                                         const QString Qslut_tid,
                                         const QString Qdag)
{
    {
        QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("Databas");
        mydb.open();

        QSqlQuery query;
        query.exec("SELECT * FROM bokning WHERE typ = '" + Qobjekttyp + "' AND objektnamn = '"+ Qobjektnamn +"' AND start_tid = '" + Qstart_tid + "' AND slut_tid = '"+ Qslut_tid+"' AND dag = '" + Qdag + "'");

        QVector<QString> bokningslista;

        while(query.next())
        {
            QString typ = query.value(0).toString();
            QString namn = query.value(1).toString();
            QString starttid = query.value(2).toString();
            QString sluttid = query.value(3).toString();
            QString dag = query.value(4).toString();
            bokningslista.push_back(typ);
            bokningslista.push_back(namn);
            bokningslista.push_back(starttid);
            bokningslista.push_back(sluttid);
            bokningslista.push_back(dag);
        }
        return bokningslista;
        mydb.close();
    }
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}


/* ------allasal _select--------
 *Plockar ut alla tider en specifik sal är bokad på*/
/*QSqlQuery Databas::allasal_select(...)
{
  QSqlQuery query;
  query.exec("SELECT * FROM bokning WHERE typ = (:Qobjekttyp) AND"
  "Qobjektnamn = (:Qobjektnamn)");
	      
  return query;
}
*/
/*------ allabokning_select--------
 *Plockar ut alla bokningar under vald dag*/
/*QSqlQuery Databas::allabokning_select(...)
{
  QsqlQuery query;
  query.exec("SELECT * FROM bokning WHERE Qdag = (:Qdag)");

  return query;
}
*/

/*--------- Sjukhus_select----------
 * Plockar ut från table personal, salar eller utrustning åt
 *klasserna Bokningsmeny och Avbokningsmeny */
QVector<QString> Databas::sjukhus_select(const QString alternativ)
{

    if (alternativ == "personal")
    {
    {
        QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("Databas");
        mydb.open();

        qDebug() << "Går in i personal";
        QSqlQuery query;
        query.exec("SELECT efternamn FROM personal");

        QVector<QString> namnlista;

        while(query.next())
        {
            QString name = query.value(0).toString();
            namnlista.push_back(name);
        }

        return namnlista;
        mydb.close();
    }
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
    }



    else if (alternativ == "salar")
    {
        {
            QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
            mydb.setDatabaseName("Databas");
            mydb.open();

            qDebug() << "Går in i salar";
            QSqlQuery query;
            query.exec( "SELECT namn FROM  salar");

            QVector<QString> namnlista;

            while(query.next())
            {
                QString name = query.value(0).toString();
                namnlista.push_back(name);
            }
            return namnlista;
            mydb.close();
        }
        QSqlDatabase::removeDatabase("qt_sql_default_connection");
    }

    else
    {
        {
            qDebug() << "Går in i utrustning";
            QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
            mydb.setDatabaseName("Databas");
            mydb.open();

            QSqlQuery query;
            query.exec( "SELECT namn FROM  utrustning");

            QVector<QString> namnlista;

            while(query.next())
            {
                QString name = query.value(0).toString();
                namnlista.push_back(name);
            }
            return namnlista;
            mydb.close();
        }
        QSqlDatabase::removeDatabase("qt_sql_default_connection");
    }
}

