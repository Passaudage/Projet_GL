#ifndef ETAT26_H
#define ETAT26_H
#include "Etat.hpp"

class Etat26 : public Etat
{
    public:
        Etat26();

    void transition(Automate* a, Symbole* s);
};

#endif // ETAT26_H
