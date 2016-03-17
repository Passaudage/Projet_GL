#ifndef ETAT33_H
#define ETAT33_H
#include "Etat.hpp"

class Etat33
{
    public:
        Etat33();
        virtual ~Etat33();
void transition(Automate* a, Symbole* s);
};

#endif // ETAT33_H
