#include "symboles/ExpressionAddition.hpp"

#include <iostream>


int ExpressionAddition::calculer(Programme& programme)
{
	return _exprGauche.calculer(programme) + _exprDroite.calculer(programme);
}

ExpressionAddition::ExpressionAddition(
		Expression& exprGauche,
		Expression& exprDroite
	):ExpressionBinaire(exprGauche, exprDroite)
{
}

void ExpressionAddition::afficher()
{
	_exprGauche.afficher();
	std::cout << "+";
	_exprDroite.afficher();
}