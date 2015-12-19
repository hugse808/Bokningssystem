  /* Personal.h
*
*BESKRIVNING: Subklass till Sjukhus.
*Klassen är personalobjekt.
*
* FÖRFATTARE: Marija Dahm
*
*/

#include "Personal.h"
#include "Databas.h"
#include <string>


using namespace std;

/*-------PERSONAL-----------
 *----defaultkonstruktor----*/

Personal::Personal (const string typ,
                    const string namn,
                    const string efternamn,
                    const string specialitet)
  :Sjukhus (typ, namn, efternamn,  specialitet, 0)
{
    Databas databasobjekt;
    databasobjekt.sjukhus_insert(*this);
}

