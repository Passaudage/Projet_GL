#include "symboles/ExpressionAddition.hpp"
#include "symboles/Valeur.hpp"

#include <iostream>

#include "symboles/ExpressionSoustraction.hpp"

ExpressionAddition::ExpressionAddition(
		Expression& exprGauche,
		Expression& exprDroite
	):ExpressionBinaire(exprGauche, exprDroite, true, 0, Symbole::Type::OPERATEUR_ADD)
{
}

void ExpressionAddition::afficher()
{
	_exprGauche->afficher();

	// permet d'éviter l'affichage "variable+-50"
	if(!(_exprDroite->getInitType() == Symbole::Type::VALEUR &&
		((Valeur*)_exprDroite)->getValeur() < 0)) {
		std::cout << "+";
	}
	
	_exprDroite->afficher();
}

int ExpressionAddition::operation(int a, int b, bool oppose)
{
	if(oppose) {
		return a - b;
	}

	return a + b;
}

ExpressionBinaire* ExpressionAddition::construireExpression(
	Expression* exprGauche, Expression* exprDroite, bool oppose)
{
	if(!oppose) {
		return new ExpressionAddition(*exprGauche, *exprDroite);
	}

	return new ExpressionSoustraction(*exprGauche, *exprDroite);
}

Expression* ExpressionAddition::simplifier(Programme& programme)
{
	Expression* expr = simplifierElementNeutre(programme);

	if(expr != this) {
		invaliderExpression();
		delete this;
		return expr;
	}

	return this;
}

