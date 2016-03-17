#ifndef ETAT29_H
#define ETAT29_H
#include "Etat.hpp"

class Etat29
{
    public:
        Etat29();
        virtual ~Etat29();

    void transition(Automate* a, Symbole* s);
};

#endif // ETAT29_H
