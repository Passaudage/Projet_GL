#ifndef ETAT21_H
#define ETAT21_H
#include "Etat.hpp"

class Etat21: public Etat
{
    public:
        Etat21();
		void transition(Automate* a, Symbole* s);
};

#endif // ETAT21_H
