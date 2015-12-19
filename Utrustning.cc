/* Utrustning.cc
*
*BESKRIVNING: Subklass till Sjukhus.
*Klassen är utrustningsobjekt
*
* FÖRFATTARE: Marija Dahm, Alex Mourad
*/


#include "Utrustning.h"
#include "Databas.h"
#include <string>

using namespace std;

/*-------UTRUSTNING-----------
 *----defaultkonstruktor----*/

Utrustning::Utrustning (const string typ,
                        const string namn,
                        const string specialitet)
    :Sjukhus(typ, namn, "",  specialitet, 0)
{
     Databas databasobjekt;
        databasobjekt.sjukhus_insert(*this);
}
