#include "symboles/ExpressionDivision.hpp"

#include <iostream>


int ExpressionDivision::calculer(Programme& programme)
{
	return _exprGauche.calculer(programme) / _exprDroite.calculer(programme);
}

ExpressionDivision::ExpressionDivision(
		Expression& exprGauche,
		Expression& exprDroite
	):ExpressionBinaire(exprGauche, exprDroite)
{
}

void ExpressionDivision::afficher()
{
	_exprGauche.afficher();
	std::cout << "/";
	_exprDroite.afficher();
}