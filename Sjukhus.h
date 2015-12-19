/* Sjukhus.h
 *
 *BESKRIVNING: Abstrakt basklass för Personal, Salar och Utrustning.
 *
 * FÖRFATTARE: Marija Dahm
 */

#ifndef SJUKHUS_H
#define SJUKHUS_H

#include <string>
using namespace std;


/*-------------SJUKHUS----------------
 */

class Sjukhus
{

public:
//Medlemsfunktioner
    string get_typ() const;
    string get_namn() const;
    string get_efternamn() const;
    string get_specialitet() const;
    int get_kapacitet() const;


protected:
//Defaultkonstruktor
  explicit Sjukhus(const string typ,
            const string namn, 
            const string efternamn,
            const string specialitet,
            const int kapacitet = 0);

//Kopieringskonstruktor
    Sjukhus(const Sjukhus&) = default;

//Destruktor
    virtual ~Sjukhus() = default;   


//Datamedlemmar
    string          typ;
    string          namn;
    string          efternamn;
    string          specialitet;
    int             kapacitet;

};

#endif
