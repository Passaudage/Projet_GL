#include <iostream>
#include "etats/Etat30.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"

Etat30::Etat30()
{
    //ctor
}

void Etat30::transition(Automate* a, Symbole* ) //réduction règle 19
{
#ifdef MAP
	std::cout << "Etat30" << std::endl;
#endif
    Symbole* id = a->symboleCourant();
    id->setType(Symbole::FACTEUR);
	a-> popEtat();
	a->etatCourant()->transition(a, id);
}
