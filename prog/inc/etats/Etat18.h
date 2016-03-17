#ifndef ETAT18_H
#define ETAT18_H

#include "Etat.hpp"

class Etat18
{
    public:
        Etat18();
        virtual ~Etat18();
void transition(Automate* a, Symbole* s);

};

#endif // ETAT18_H
