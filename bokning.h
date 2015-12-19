/*bokning.h
 *
 * Beskrivning: Deklaration av en bokning och dess funktioner.
 *
 * Författare: Anton Lindman
 *
 */

#ifndef BOKNING_H
#define BOKNING_H

//includes
#include <string>
using namespace std;

class Bokning
{
public:
//Defaultkonstruktor
    Bokning(string typ,
            string objektnamn,
            const double start_tid,
            const double slut_tid,
            const int dag);

    //Medlemsfunktioner
    string get_typ() const;
    string get_objektnamn() const;
    double get_start_tid() const;
    double get_slut_tid() const;
    int get_dag() const;

// start_tid och slut_tid kommer att ha begränsningar.
// Tiden kommer att visas i tt.mm och minuter kommer inte att kunna överstiga 59. 

//Destruktor
    ~Bokning() = default;

private:
//Datamedlemmar
    string typ{};
    string objektnamn{};
    double start_tid{};
    double slut_tid{};
    int dag{};
};

#endif
