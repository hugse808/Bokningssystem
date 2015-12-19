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

Avbokning::Avbokning(string typ,
                     string objektnamn, 
                     const double start_tid, 
                     const double slut_tid, 
                     const int dag) 
    : 
    typ{typ},
    objektnamn{objektnamn}, 
    start_tid{start_tid}, 
    slut_tid{slut_tid}, 
    dag{dag}
{
    Databas databasobjekt;
    databasobjekt.avbokning_delete(*this);
}

//Diverse get-funktioner
string Avbokning::get_typ() const
{
    return typ;
}

string Avbokning::get_objektnamn() const
{
    return objektnamn;
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
