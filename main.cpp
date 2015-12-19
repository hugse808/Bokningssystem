/*main.cpp
 *
 * Beskrivning: Startar programmet med konstruktorer samt skapar databasfil.
 *
 * Författare: Marija Dahm, Alex Mourad, Hugo Severinsson
 *
 */

#include "meny.h"
#include "Databas.h"
#include "Utrustning.h"
#include "Salar.h"
#include "Personal.h"
#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>

static const QString databas = "/home/hugse808/TDDC76/QTprojekt/Projekt - aktiv fil/build-Bokningssystem-Desktop-Debug/Databas";

int main(int argc, char **argv)
{
    QApplication app (argc, argv);


    {
        //Skapar databas
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("Databas");

        bool opened = db.open();
        if(opened)
        {
            qDebug( "Ansluten!");
            QSqlQuery query;
            query.exec("CREATE TABLE IF NOT EXISTS personal (typ TEXT, namn TEXT, efternamn TEXT, specialitet TEXT)");
            query.exec("CREATE TABLE IF NOT EXISTS salar (typ TEXT, namn TEXT, specialitet TEXT, kapacitet TEXT)");
            query.exec("CREATE TABLE IF NOT EXISTS utrustning (typ TEXT, namn TEXT, specialitet TEXT)");
            query.exec("CREATE TABLE IF NOT EXISTS bokning (typ TEXT, objektnamn TEXT, start_tid TEXT, slut_tid TEXT, dag TEXT)");

           //query.exec("DELETE FROM bokning");

            bool create = query.exec();
            if(!create)
            {
                qDebug() <<db.lastError().text();
            }
        }
        else
        {
            qDebug() << db.lastError().text();
            qFatal( "Anslutningen misslyckades" );
        }
        db.close();
    }

    QSqlDatabase::removeDatabase("qt_sql_default_connection");


 /*  Personal* P1 = new Personal
           {"Personal", "Marija", "Dahm", "Kardiolog"};

       Personal* P2 = new Personal
           {"Personal", "Alex", "Mourad", "Radiolog"};

       Personal* P3 = new Personal
           {"Personal", "Anton", "Lindman", "Neurolog"};

       Personal* P4 = new Personal
           {"Personal", "Stina", "Alm", "Röntgensköterska"};

       Personal* P5 = new Personal
           {"Personal", "Julia", "Stjärnholm", "Ortoped"};

       Personal* P6 = new Personal
           {"Personal", "Lars", "Holmstedt", "Pediatriker"};

       Personal* P7 = new Personal
           {"Personal", "Alvin", "Johansson", "Hematolog"};

       Personal* P8 = new Personal
           {"Personal", "Marie", "Sten", "Radiolog"};

       Personal* P9 = new Personal
           {"Personal", "Johan", "Persson", "Kirurg"};

       Personal* P10 = new Personal
           {"Personal", "Leona", "Smith", "Gynekolog"};

       Salar* S1 = new Salar
           {"Salar", "Ka1", "Kardiologi", 15};

       Salar* S2 = new Salar
           {"Salar", "R1", "Radiologi", 3};

       Salar* S3 = new Salar
           {"Salar", "R2", "Radiologi", 3};

       Salar* S4 = new Salar
           {"Salar", "R3", "Radiologi", 3};

       Salar* S5 = new Salar
           {"Salar", "N1", "Neurologi", 6};

       Salar* S6 = new Salar
           {"Salar", "O1", "Ortopedi", 5};

       Salar* S7 = new Salar
           {"Salar", "P1", "Pediatrik", 5};

       Salar* S8 = new Salar
           {"Salar", "H1", "Hematologi", 2};

       Salar* S9 = new Salar
           {"Salar", "K1", "Kirurgi", 15};

       Salar* S10 = new Salar
           {"Salar", "G1", "Gynekologi", 2};
       Utrustning* U1 = new Utrustning
           {"Utrustning", "EKG", "Kardiologi" };

       Utrustning* U2 = new Utrustning
           {"Utrustning", "CT", "Radiologi" };

       Utrustning* U3 = new Utrustning
           {"Utrustning", "PET", "Radiologi" };

       Utrustning* U4 = new Utrustning
           {"Utrustning", "MR", "Radiologi" };

       Utrustning* U5 = new Utrustning
           {"Utrustning", "Neurologisk borrmaskin", "Neurologi" };

       Utrustning* U6 = new Utrustning
           {"Utrustning", "Ortopedisk såg", "Ortopedi" };


       Utrustning* U7 = new Utrustning
           {"Utrustning", "Stetoskop", "Pediatrik" };

       Utrustning* U8 = new Utrustning
           {"Utrustning", "Ultraljudsmaskin", "Hematologi" };

       Utrustning* U9 = new Utrustning
           {"Utrustning", "Skalpell", "Kirurgi" };

       Utrustning* U10 = new Utrustning
           {"Utrustning", "Sims Uterine Curette", "Gynekologi" };
*/

    meny nymeny;
    nymeny.show();

    return app.exec();
}
