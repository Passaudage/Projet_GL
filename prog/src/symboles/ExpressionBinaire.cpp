#include "symboles/ExpressionBinaire.hpp"

#include <iostream>

ExpressionBinaire::ExpressionBinaire(Expression& exprGauche, Expression& exprDroite):
	Expression(FACTEUR),_exprGauche(exprGauche),_exprDroite(exprDroite)
{
}

ExpressionBinaire::~ExpressionBinaire()
{
	delete &_exprDroite;
	delete &_exprGauche;
}

