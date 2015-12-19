/*Avbokning.h
 *
 * Beskrivning: Deklaration av en avbokning och dess funktioner.
 *
 * Författare: Anton Lindman
 *
 */

#ifndef AVBOKNING_H
#define AVBOKNING_H

//includes
#include <string>
using namespace std;

class Avbokning
{
public:
//Defaultkonstruktor
    Avbokning(string typ,
              string objektnamn,
              const double start_tid,
              const double slut_tid,
              const int dag);

    //Destruktor
    ~Avbokning() = default;

    //Medlemsfunktioner
    string get_typ() const;
    string get_objektnamn() const;
    double get_start_tid() const;
    double get_slut_tid() const;
    int get_dag() const;

private:
    //Datamedlemmar
    string typ{};
    string objektnamn{};
    double start_tid{};
    double slut_tid{};
    int dag{};
};

#endif
