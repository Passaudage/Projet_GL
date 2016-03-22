#include "symboles/ExpressionBinaire.hpp"

#include <iostream>

#include "symboles/Identifiant.hpp"

ExpressionBinaire::ExpressionBinaire(Expression& exprGauche, Expression& exprDroite):
	Expression(FACTEUR),_exprGauche(exprGauche),_exprDroite(exprDroite)
{
}

ExpressionBinaire::~ExpressionBinaire()
{
	delete &_exprDroite;
	delete &_exprGauche;
}

std::unordered_set<Identifiant*> ExpressionBinaire::getIdentifiants()
{
	std::unordered_set<Identifiant*> set_a = _exprGauche.getIdentifiants();
	std::unordered_set<Identifiant*> set_b = _exprDroite.getIdentifiants();

	set_a.insert(set_b.begin(), set_b.end());

	return set_a;
}