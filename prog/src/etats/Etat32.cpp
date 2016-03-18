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
	Expression* expr_droit = (Expression*) a->popSymbole();
	OperateurMult* opM = (OperateurMult*) a->popSymbole();
	Expression* expr_gauche = (Expression*) a->popSymbole();
	Expression* expr;
	if(opM->estMultiplie()){
		expr = new ExpressionMultiplication(*expr_gauche, *expr_droit);
	} else {
		expr = new ExpressionDivision(*expr_gauche, *expr_droit);
	}

	a->popEtat();
	a->popEtat();
	a->popEtat();
	a->etatCourant()->transition(a, expr);
}
