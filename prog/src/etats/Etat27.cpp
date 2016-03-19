#include <iostream>
#include "etats/Etat27.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"

Etat27::Etat27()
{
    //ctor
}

void Etat27::transition(Automate* a, Symbole* ) //réduction règle 18
{
	Symbole* expr = a->popSymbole();
	expr->setType(Symbole::FACTEUR);
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a->etatCourant()->transition(a, expr);
}
