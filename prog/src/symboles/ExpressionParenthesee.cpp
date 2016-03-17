#include "symboles/ExpressionParenthesee.hpp"

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
