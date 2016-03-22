#include "symboles/ExpressionParenthesee.hpp"

#include <iostream>

#include "symboles/Identifiant.hpp"

int ExpressionParenthesee::calculer(Programme& programme)
{
	return _exprInter.calculer(programme);
}

ExpressionParenthesee::ExpressionParenthesee(Expression& exprInter):
	Expression(FACTEUR),_exprInter(exprInter)
{
}

ExpressionParenthesee::~ExpressionParenthesee()
{
	delete &_exprInter;
}

void ExpressionParenthesee::afficher()
{
	std::cout << "(";
	_exprInter.afficher();
	std::cout << ")";
}

std::unordered_set<Identifiant*> ExpressionParenthesee::getIdentifiants()
{
	return _exprInter.getIdentifiants();
}