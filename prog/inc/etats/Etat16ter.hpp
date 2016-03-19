#ifndef ETAT16TER_H
#define ETAT16TER_H
#include "Etat.hpp"

class Etat16ter : public Etat
{
    public:
        Etat16ter();
        virtual ~Etat16ter();

   void transition(Automate* a, Symbole* s);
};

#endif // ETAT16TER_H
