
#ifndef ETAT32_H
#define ETAT32_H
#include "Etat.hpp"

class Etat32 : public Etat
{
    public:
        Etat32();
        virtual ~Etat32();

   void transition(Automate* a, Symbole* );
};

#endif // ETAT32_H
