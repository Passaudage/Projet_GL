#include <iostream>
#include "etats/Etat24.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"

Etat24::Etat24()
{
    //ctor
}

void Etat24::transition(Automate* a, Symbole* ) //réduction règle 17
{
#ifdef MAP
	std::cout << "Etat24" << std::endl;
#endif
	
	Symbole* terme = a->popSymbole();
	terme->setType(Symbole::TERME);
	a->etatCourant()->transition(a, terme);
}
