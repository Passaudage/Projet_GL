#include <iostream>
#include "etats/Etat24.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"

Etat24::Etat24()
{
    //ctor
}

void Etat24::transition(Automate* a, Symbole* terme) //réduction règle 17
{
#ifdef MAP
	std::cout << "Etat24" << std::endl;
#endif
	
	terme->setType(Symbole::TERME);
	a-> popEtat();
	a->etatCourant()->transition(a, terme);
}
