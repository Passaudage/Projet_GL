#include "symboles/ExpressionSoustraction.hpp"

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
