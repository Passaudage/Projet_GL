#include <iostream>
#include "etats/Etat32.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/ExpressionMultiplication.hpp"
#include "symboles/ExpressionDivision.hpp"
#include "symboles/SymbolesTerminaux.hpp"
#include "symboles/Expression.hpp"

Etat32::Etat32()
{
    //ctor
}

Etat32::~Etat32()
{
    //dtor
}

void Etat32::transition(Automate* a, Symbole* ) //réduction règle 16
{
	// OK
	std::cout << "Etat32" << std::endl;
	Symbole* val = a->popSymbole();
    val->setType(Symbole::FACTEUR);
	a-> popEtat();
	a->etatCourant()->transition(a, val);
}
