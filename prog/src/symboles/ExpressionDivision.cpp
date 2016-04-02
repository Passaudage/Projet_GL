#include "symboles/ExpressionDivision.hpp"
#include "symboles/Valeur.hpp"

#include <iostream>

#include "symboles/ExpressionMultiplication.hpp"

#include "Erreurs.hpp"

ExpressionDivision::ExpressionDivision(
		Expression& exprGauche,
		Expression& exprDroite
	):ExpressionBinaire(exprGauche, exprDroite, false, 1, Symbole::Type::OPERATEUR_MUL)
{
}

void ExpressionDivision::afficher()
{
	_exprGauche->afficher();
	std::cout << "/";
	_exprDroite->afficher();
}

int ExpressionDivision::operation(int a, int b, bool oppose)
{
	if(oppose) {
		return a * b;
	}

	if(b == 0) {
		throw ExceptionFarfadet(ExceptionFarfadet::division_zero);
	}

	return a / b;
}

ExpressionBinaire* ExpressionDivision::construireExpression(
	Expression* exprGauche, Expression* exprDroite, bool oppose)
{
	if(!oppose) {
		return new ExpressionDivision(*exprGauche, *exprDroite);
	}

	return new ExpressionMultiplication(*exprGauche, *exprDroite);
}

Expression* ExpressionDivision::simplifier(Programme& programme)
{

	Expression* expr = simplifierElementNeutre(programme);

	if(expr != this) {
		invaliderExpression();
		delete this;
		return expr;
	}

	if((_exprGauche->estEvaluable(programme) &&
		_exprGauche->calculer(programme) == 0))  {
		delete this;
		return new Valeur(0);
	}

	return this;
}
