/* Salar.h
*
*BESKRIVNING: Subklass till Sjukhus.
*Klassen är salsobjekt.
*
* FÖRFATTARE: Marija Dahm
*/

#ifndef SALAR_H
#define SALAR_H

#include "Sjukhus.h"
#include <string>

using namespace std;

/*-------------Salar-----------------
 */

class Salar : public Sjukhus
{
public:
//Defaultkonstruktor
    Salar(const string typ,
          const string namn, 
          const string specialitet, 
          const int kapacitet);

//Kopieringskonstruktor
    Salar(const Salar&) = default;

//Destruktor
    ~Salar() = default;

};

#endif
