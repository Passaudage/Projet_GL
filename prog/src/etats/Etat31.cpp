#include <iostream>
#include "etats/Etat31.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"

Etat31::Etat31()
{
    //ctor
}

void Etat31::transition(Automate* a, Symbole* ) //réduction règle 20
{
#ifdef MAP
	std::cout << "Etat31" << std::endl;
#endif
    Symbole* id = a->symboleCourant();
    id->setType(Symbole::FACTEUR);
	a-> popEtat();
	a->etatCourant()->transition(a, id);
}
