/*bokning.cc
 *
 * Beskrivning: Definition av bokningar och dess funktioner.
 *
 * Författare: Anton Lindman och Hugo Severinsson
 *
 */

//includes
#include "bokning.h"
#include "Databas.h"

Bokning::Bokning(string stdobjekttyp,
                 string stdobjektnamn,
                 const double start_tid,
                 const double slut_tid,
                 const int dag)
    : 
    typ{stdobjekttyp},
    objektnamn{stdobjektnamn},
    start_tid{start_tid},
    slut_tid{slut_tid},
    dag{dag}
{
    Databas databasobjekt;
    databasobjekt.bokning_insert(*this);
}

string Bokning::get_typ() const
{
    return typ;
}

string Bokning::get_objektnamn() const
{
    return objektnamn;
}

double Bokning::get_start_tid() const
{
    return start_tid;
}

double Bokning::get_slut_tid() const
{
    return slut_tid;
}

int Bokning::get_dag() const
{
    return dag;
}
