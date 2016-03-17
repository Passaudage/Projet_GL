#include "Etat32.h"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/ExpressionMultiplication.h"
#include "symboles/Expression.h"
#include "symboles/OperateurMult.h"
#include "symboles/ExpressionDivision.h"

Etat32::Etat32()
{
    //ctor
}

Etat32::~Etat32()
{
    //dtor
}
void Etat32::transition(Automate* a, Symbole* s) //réduction règle 16
{
	Symbole* expr_droite = (Expression*) a->popSymbole();
	Symbole* opM = (OperateurMult*) a->popSymbole();
	Symbole* expr_gauche = (Expression*) a->popSymbole();
	Symbole* expr;
	if(opM.estMultiplie()){
		expr = new ExpressionMultiplication(*expr_gauche, *expr_droit);
	} else {
		expr = new ExpressionDivision(*expr_gauche, *expr_droit);
	}

	a->popEtat();
	a->popEtat();
	a->popEtat();
	a->etatCourant()->transition(a, expr)
}
