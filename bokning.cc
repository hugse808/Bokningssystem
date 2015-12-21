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

Bokning::Bokning(string stdsalnamn,
                 string stdpersonalnamn,
                 string stdutrustningnamn,
                 const double start_tid,
                 const double slut_tid,
                 const int dag)
    : 
    salnamn{stdsalnamn},
    personalnamn{stdpersonalnamn},
    utrustningnamn{stdutrustningnamn},
    start_tid{start_tid},
    slut_tid{slut_tid},
    dag{dag}
{
    Databas databasobjekt;
    databasobjekt.bokning_insert(*this);
}

string Bokning::get_salnamn() const
{
    return salnamn;
}

string Bokning::get_personalnamn() const
{
    return personalnamn;
}

string Bokning::get_utrustningnamn() const
{
  return utrustningnamn;
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
