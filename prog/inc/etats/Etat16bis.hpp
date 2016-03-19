#ifndef ETAT16BIS_H
#define ETAT16BIS_H
#include "Etat.hpp"

class Etat16bis : public Etat
{
    public:
        Etat16bis();
		void transition(Automate* a, Symbole* s);
};

#endif // ETAT16BIS_H
