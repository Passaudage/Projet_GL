#ifndef ETAT19_H
#define ETAT19_H
#include "Etat.hpp"

class Etat19
{
    public:
        Etat19();
        virtual ~Etat19();

    void transition(Automate* a, Symbole* s);
};

#endif // ETAT19_H