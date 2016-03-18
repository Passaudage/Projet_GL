#ifndef ETAT34_H
#define ETAT34_H
#include "Etat.hpp"

class Etat34 : public Etat
{
    public:
        Etat34();
        virtual ~Etat34();

   void transition(Automate* a, Symbole* s);
};

#endif // ETAT34_H
