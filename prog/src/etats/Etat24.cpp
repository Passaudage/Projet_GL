#include <iostream>
#include "etats/Etat24.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"

Etat24 Etat24::m_instance = Etat24();

Etat24::Etat24()
{
}

Etat24* Etat24::getInstance(){
	return &m_instance;
}


void Etat24::transition(Automate* a, Symbole* ) //réduction règle 17
{
#ifdef MAP
	std::cout << "Etat24" << std::endl;
#endif
	
	Symbole* terme = a->symboleCourant();
	terme->setType(Symbole::TERME);
	a->popEtat();
	a->etatCourant()->transition(a, terme);
}
