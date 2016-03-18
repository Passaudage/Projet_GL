#include "symboles/ExpressionSoustraction.hpp"

#include <iostream>


int ExpressionSoustraction::calculer(Programme& programme)
{
	return _exprGauche.calculer(programme) - _exprDroite.calculer(programme);
}

ExpressionSoustraction::ExpressionSoustraction(
		Expression& exprGauche,
		Expression& exprDroite
	):ExpressionBinaire(exprGauche, exprDroite)
{
}

void ExpressionSoustraction::afficher()
{
	_exprGauche.afficher();
	std::cout << "-";
	_exprDroite.afficher();
}
