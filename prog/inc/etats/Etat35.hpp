#ifndef ETAT35_HPP
#define ETAT35_HPP
#include "Etat.hpp"

class Etat35 : public Etat
{
    public:
        Etat35();
		void transition(Automate* a, Symbole* s);
};

#endif // ETAT35_HPP
