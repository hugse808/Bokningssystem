/*Avbokning.cc
 *
 * Beskrivning: Definition av avbokningar och dess funktioner.
 *
 * Författare: Anton Lindman och Hugo Severinsson
 *
 */

//includes
#include "Databas.h"
#include "Avbokning.h"

Avbokning::Avbokning(string salnamn,
                     const double start_tid,
                     const double slut_tid,
                     const int dag)
    :
    salnamn{salnamn},
    start_tid{start_tid},
    slut_tid{slut_tid},
    dag{dag}
{
    Databas databasobjekt;
    databasobjekt.avbokning_delete(*this);
}

//Diverse get-funktioner
string Avbokning::get_salnamn() const
{
    return salnamn;
}

double Avbokning::get_start_tid() const
{
    return start_tid;
}

double Avbokning::get_slut_tid() const
{
    return slut_tid;
}

int Avbokning::get_dag() const
{
    return dag;
}
