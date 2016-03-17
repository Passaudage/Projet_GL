#ifndef ETAT32_H
#define ETAT32_H
#include "Etat.hpp"

class Etat32
{
    public:
        Etat32();
        virtual ~Etat32();

   void transition(Automate* a, Symbole* s);
};

#endif // ETAT32_H
