#ifndef ETAT18_H
#define ETAT18_H

#include "Etat.hpp"

class Etat18: public Etat
{
    public:
        Etat18();
		void transition(Automate* a, Symbole* );
};

#endif // ETAT18_H
