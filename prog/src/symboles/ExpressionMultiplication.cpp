#include "symboles/ExpressionMultiplication.hpp"

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
