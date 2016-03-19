#ifndef ETAT23_H
#define ETAT23_H
#include "Etat.hpp"

class Etat23 : public Etat
{
    public:
        Etat23();
		void transition(Automate* a, Symbole* s);
};

#endif // ETAT23_H
