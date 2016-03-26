#include "symboles/ExpressionSoustraction.hpp"
#include "symboles/Valeur.hpp"

#include <iostream>

#include "symboles/ExpressionAddition.hpp"


ExpressionSoustraction::ExpressionSoustraction(
		Expression& exprGauche,
		Expression& exprDroite
	):ExpressionBinaire(exprGauche, exprDroite, false, 0, Symbole::Type::OPERATEUR_ADD)
{
}

void ExpressionSoustraction::afficher()
{
	// permet d'éviter l'affichage "0-variable"
	if(!(_exprGauche->getInitType() == Symbole::Type::VALEUR &&
		((Valeur*)_exprGauche)->getValeur() == 0)) {
		_exprGauche->afficher();
	}

	std::cout << "-";
	_exprDroite->afficher();
}

int ExpressionSoustraction::operation(int a, int b, bool oppose)
{
	if(oppose) {
		return a + b;
	}
	return a - b;
}

Expression* ExpressionSoustraction::simplifier(Programme& programme)
{
	Expression* expr = simplifierElementNeutre(programme);

	if(expr != this) {
		return expr;
	}

	if(_exprDroite->getInitType() == Symbole::Type::VALEUR &&
		((Valeur*)_exprDroite)->getValeur() < 0) {
		return new ExpressionAddition(*_exprGauche, 
			* new Valeur(-((Valeur*)_exprDroite)->getValeur() ));
	}

	return this;
}

ExpressionBinaire* ExpressionSoustraction::construireExpression(
	Expression* exprGauche, Expression* exprDroite, bool oppose)
{
	if(oppose) {
		return new ExpressionAddition(*exprGauche, *exprDroite);
	}

	return new ExpressionSoustraction(*exprGauche, *exprDroite);
}

/*
Expression* ExpressionSoustraction::optimiser(Programme& programme)
{
	//~ std::cout << "Expression Soustraction optimisation "<<std::endl;
	Expression* left = _exprGauche->optimiser(programme);
	Expression* right = _exprDroite->optimiser(programme);

	if(left->estEvaluable(programme) && right->estEvaluable(programme)) {
		return new Valeur(left->calculer(programme)-right->calculer(programme));
	}
	else {
		if(left->estEvaluable(programme)) {
			if(left->calculer(programme) == 0) {
				return right;
			}
		}
		else if(right->estEvaluable(programme)) {
			if(right->calculer(programme) == 0) {
				return left;
			}
		}
		return new ExpressionSoustraction(*left,*right);
	}
}
*/