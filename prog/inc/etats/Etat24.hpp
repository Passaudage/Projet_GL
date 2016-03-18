#ifndef ETAT24_H
#define ETAT24_H
#include "Etat.hpp"

class Etat24 : public Etat
{
    public:
        Etat24();
        virtual ~Etat24();

  void transition(Automate* a, Symbole* s);
};

#endif // ETAT24_H
