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

	Symbole* facteur = a->popSymbole();
	facteur->setType(Symbole::FACTEUR);
	a-> popEtat();
	a->etatCourant()->transition(a, facteur);
}
