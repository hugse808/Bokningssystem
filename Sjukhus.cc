
/* Sjukhus.cc
 *
 *BESKRIVNING: Abstrakt basklass för Personal, Salar och Utrustning.
 *
 * FÖRFATTARE: Marija Dahm
 */


//Inkluderingar
#include "Sjukhus.h"

using namespace std;

/*------------SJUKHUS--------------
 *---------defaultkonstruktor-----*/

Sjukhus::Sjukhus(const string typ,
                 const string namn,
                 const string efternamn,
                 const string specialitet,
                 const int kapacitet)
    : 
    typ{typ},
    namn{namn},
    efternamn{efternamn},
    specialitet{specialitet},
    kapacitet{kapacitet}
{}


/*------------SJUKHUS--------------
 *---------Medlemsfunktioner-----*/

//get_typ
string Sjukhus::get_typ() const
{
        return typ;
}

//get_namn
string Sjukhus::get_namn() const
{
        return namn;
}

//get_efternamn
string Sjukhus::get_efternamn() const
{
        return efternamn;
}

//get_specialitet
string Sjukhus::get_specialitet() const
{
        return specialitet;
}

//get_kapacitet
int Sjukhus::get_kapacitet() const
{
        return kapacitet;
}

