#include "symboles/ExpressionAddition.hpp"

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
