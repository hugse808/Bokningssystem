/* Salar.cc
*
*BESKRIVNING: Subklass till Sjukhus.
*Klassen är salsobjekt.
*
* FÖRFATTARE: Marija Dahm
*/


#include "Salar.h"
#include "Databas.h"
#include <string>

using namespace std;

/*-------SALAR----------
 *----defaultkonstruktor----*/

Salar::Salar (const string typ,
              const string namn,
              const string specialitet,
              const int kapacitet)
    :Sjukhus (typ, namn, "",  specialitet, kapacitet)
{
     Databas databasobjekt;
        databasobjekt.sjukhus_insert(*this);
}
