/* Utrustning.h
*
*BESKRIVNING: Subklass till Sjukhus.
*Klassen är utrustningsobjekt
*
* FÖRFATTARE: Marija Dahm, Alex Mourad
*/

#ifndef UTRUSTNING_H
#define UTRUSTNING_H

#include "Sjukhus.h"
#include <string>

using namespace std;

/*------------UTRUSTNING-----------------
 *---------------------------------------*/

class Utrustning : public Sjukhus
{
public:
//Defaultkonstruktor
    Utrustning(const string typ,
               const string namn, 
               const string specialitet);

//Kopieringskonstruktor
Utrustning(const Utrustning&) = default;

//Destruktor
~Utrustning() = default;
};
#endif
