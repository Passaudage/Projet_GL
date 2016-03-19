#include <iostream>
#include "etats/Etat24.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"

Etat24::Etat24()
{
    //ctor
}

Etat24::~Etat24()
{
    //dtor
}
void Etat24::transition(Automate* a, Symbole* s) //réduction règle 17
{
	std::cout << "Etat24" << std::endl;
	s->setType(Symbole::TERME);
	a-> popEtat();
	a->etatCourant()->transition(a, s);
}
