#include "symboles/ExpressionParenthesee.hpp"

#include <iostream>

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