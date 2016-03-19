#include <iostream>
#include "etats/Etat27.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"

Etat27::Etat27()
{
    //ctor
}

Etat27::~Etat27()
{
    //dtor
}
void Etat27::transition(Automate* a, Symbole* ) //réduction règle 18
{
    a->popSymbole();
	Symbole* expr = a->popSymbole();
	expr->setType(Symbole::FACTEUR);
	a->popSymbole();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a->etatCourant()->transition(a, expr);
}
