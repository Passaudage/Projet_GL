#ifndef ETAT20_H
#define ETAT20_H
#include "Etat.hpp"

class Etat20
{
    public:
        Etat20();
        virtual ~Etat20();

    void transition(Automate* a, Symbole* s);
};

#endif // ETAT20_H
