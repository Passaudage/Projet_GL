#include "symboles/ExpressionMultiplication.hpp"

#include <iostream>


int ExpressionMultiplication::calculer(Programme& programme)
{
	return _exprGauche.calculer(programme) * _exprDroite.calculer(programme);
}

ExpressionMultiplication::ExpressionMultiplication(
		Expression& exprGauche,
		Expression& exprDroite
	):ExpressionBinaire(exprGauche, exprDroite)
{
}

void ExpressionMultiplication::afficher()
{
	_exprGauche.afficher();
	std::cout << "*";
	_exprDroite.afficher();
}