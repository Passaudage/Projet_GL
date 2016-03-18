#ifndef ETAT22_H
#define ETAT22_H
#include "Etat.hpp"

class Etat22: public Etat
{
    public:
        Etat22();
        virtual ~Etat22();
void transition(Automate* a, Symbole* s);
};

#endif // ETAT22_H
