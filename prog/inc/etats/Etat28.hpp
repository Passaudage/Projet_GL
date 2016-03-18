#ifndef ETAT28_H
#define ETAT28_H
#include "Etat.hpp"

class Etat28 : public Etat
{
    public:
        Etat28();
        virtual ~Etat28();

    void transition(Automate* a, Symbole* s);
};

#endif // ETAT28_H
