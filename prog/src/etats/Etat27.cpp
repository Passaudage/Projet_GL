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
#ifdef MAP
	std::cout << "Etat27 : Reduction F->(Expr)" << std::endl;
#endif
	Symbole* expr = a->symboleCourant();
	expr->setType(Symbole::FACTEUR);
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a->etatCourant()->transition(a, expr);
}
