/*meny.cpp
 *
 * Beskrivning: Definition av meny och dess funktioner.
 *
 * Författare: Hugo Severinsson
 *
 */
#include "meny.h"
#include <iostream>

meny::meny(QWidget *parent) : QWidget(parent)
{
    //Bestämmer storleken för fönstret. Går inte att ändra.
    setFixedSize(900,600);

    //Skapar välkomsttext
    QLabel *label = new QLabel(this);
    label->setAlignment(Qt::AlignLeft);
    label->setIndent(410);
    label->setText("<b><br /> <br /><center> VÄLKOMMEN!<br />  <br /> Vad vill du göra?</b> <center>");

    //Skapar knappar som behövs i menyfönstret
    boka_knapp = new QPushButton("BOKA", this);
    boka_knapp->setGeometry(400,180,130,50);
    connect(boka_knapp,SIGNAL(clicked()), this, SLOT (skapa_bmeny())); //Öppnar ett bokningsfönster

    avboka_knapp = new QPushButton("AVBOKA", this);
    avboka_knapp->setGeometry(400,250,130,50);
    connect(avboka_knapp,SIGNAL(clicked()), this, SLOT(skapa_avmeny())); //Öppnar ett fönster för avbokning

    schema_knapp = new QPushButton("SE SCHEMA", this);
    schema_knapp->setGeometry(400,320,130,50);
    connect(schema_knapp,SIGNAL(clicked()), this, SLOT(skapa_smeny())); //Öppnar ett fönster för schemat

    exit_knapp = new QPushButton("AVSLUTA", this);
    exit_knapp->setGeometry(400,400,130,50);
    connect(exit_knapp,SIGNAL(clicked()), this, SLOT(avsluta()));
}

void meny::skapa_bmeny()
{
    bmeny = new bokningsmeny();
    bmeny->show();
}

void meny::skapa_avmeny()
{
    avmeny = new avbokningsmeny();
    avmeny->show();
}

void meny::skapa_smeny()
{
    smeny = new schema();
    smeny->show();
}

void meny::avsluta()
{
    QApplication::quit();
}
