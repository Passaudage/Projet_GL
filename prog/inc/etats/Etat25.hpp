#ifndef ETAT25_H
#define ETAT25_H
#include "Etat.hpp"

class Etat25 : public Etat
{
    public:
        Etat25();

   void transition(Automate* a, Symbole* s);
};

#endif // ETAT25_H
