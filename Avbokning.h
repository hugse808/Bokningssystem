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
    Avbokning(string salnamn,
              string personalnamn,
              string utrustningnamn,
              const double start_tid,
              const double slut_tid,
              const int dag);

    //Destruktor
    ~Avbokning() = default;

    //Medlemsfunktioner
    string get_salnamn() const;
    string get_personalnamn() const;
    string get_utrustningnamn() const;
    double get_start_tid() const;
    double get_slut_tid() const;
    int get_dag() const;

private:
    //Datamedlemmar
    string salnamn{};
    string personalnamn{};
    string utrustningnamn{};
    double start_tid{};
    double slut_tid{};
    int dag{};
};

#endif
