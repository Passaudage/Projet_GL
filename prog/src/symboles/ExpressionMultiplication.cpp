#include "symboles/ExpressionMultiplication.hpp"
#include "symboles/Valeur.hpp"

#include <iostream>

#include "symboles/ExpressionDivision.hpp"

ExpressionMultiplication::ExpressionMultiplication(
		Expression& exprGauche,
		Expression& exprDroite
	):ExpressionBinaire(exprGauche, exprDroite, true, 1, Symbole::Type::OPERATEUR_MUL)
{
}

void ExpressionMultiplication::afficher()
{
	_exprGauche->afficher();
	std::cout << "*";
	_exprDroite->afficher();
}

int ExpressionMultiplication::operation(int a, int b, bool oppose)
{
	if(oppose) {
		return a / b;
	}
	return a * b;
}

ExpressionBinaire* ExpressionMultiplication::construireExpression(
	Expression* exprGauche, Expression* exprDroite, bool oppose)
{
	if(oppose) {
		return new ExpressionDivision(*exprGauche, *exprDroite); 
	}

	return new ExpressionMultiplication(*exprGauche, *exprDroite);
}

Expression* ExpressionMultiplication::simplifier(Programme& programme)
{
	Expression* expr = simplifierElementNeutre(programme);

	if(expr != this) {
		invaliderExpression();
		delete this;
		return expr;
	}

	if((_exprDroite->estEvaluable(programme) &&
		_exprDroite->calculer(programme) == 0) ||
		(_exprGauche->estEvaluable(programme) &&
		_exprGauche->calculer(programme) == 0))  {
		delete this;
		return new Valeur(0);
	}

	return this;
}
