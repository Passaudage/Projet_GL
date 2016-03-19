#include <iostream>
#include "etats/Etat31.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"

Etat31::Etat31()
{
    //ctor
}

Etat31::~Etat31()
{
    //dtor
}

void Etat31::transition(Automate* a, Symbole* ) //réduction règle 20
{
	// OK
	std::cout << "Etat31" << std::endl;
    Symbole* id = a->popSymbole();
    id->setType(Symbole::FACTEUR);
	a-> popEtat();
	a->etatCourant()->transition(a, id);
}

/*
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
*/
