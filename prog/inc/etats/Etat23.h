#ifndef ETAT23_H
#define ETAT23_H
#include "Etat.hpp"

class Etat23
{
    public:
        Etat23();
        virtual ~Etat23();

    void transition(Automate* a, Symbole* s);
};

#endif // ETAT23_H
