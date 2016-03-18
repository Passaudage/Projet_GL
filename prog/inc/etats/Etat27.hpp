#ifndef ETAT27_H
#define ETAT27_H
#include "Etat.hpp"

class Etat27 : public Etat
{
    public:
        Etat27();
        virtual ~Etat27();
void transition(Automate* a, Symbole* );
};

#endif // ETAT27_H
