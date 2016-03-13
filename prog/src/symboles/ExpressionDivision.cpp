#include "symboles/ExpressionDivision.hpp"

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
