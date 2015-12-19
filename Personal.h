/* Personal.h
*
*BESKRIVNING: Subklass till Sjukhus.
*Klassen är personalobjekt
*
* FÖRFATTARE: Marija Dahm
*/

#ifndef PERSONAL_H
#define PERSONAL_H

#include "Sjukhus.h"
#include <string>

using namespace std;

/*-------------PERSONAL-----------------
*/

class Personal : public Sjukhus
{
public:
//Defaultkonstruktor
     Personal(const string typ,
           const string namn,
           const string efternamn, 
           const string specialitet);

//Kopieringskonstruktor
    Personal(const Personal&) = default;

//Destruktor
    ~Personal() = default;
};

#endif
