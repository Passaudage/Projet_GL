#ifndef ETAT27_H
#define ETAT27_H
#include "Etat.hpp"

class Etat27
{
    public:
        Etat27();
        virtual ~Etat27();
void transition(Automate* a, Symbole* s);
};

#endif // ETAT27_H