#include "symboles/ExpressionParenthesee.hpp"

#include <iostream>

#include "symboles/Identifiant.hpp"

int ExpressionParenthesee::calculer(Programme& programme)
{
	return _exprInter->calculer(programme);
}

ExpressionParenthesee::ExpressionParenthesee(Expression& exprInter):
	Expression(FACTEUR)
{
	_exprInter = &exprInter;
}

ExpressionParenthesee::~ExpressionParenthesee()
{
	if (_exprInter != nullptr) 
		delete _exprInter;
}

void ExpressionParenthesee::afficher()
{
	std::cout << "(";
	_exprInter->afficher();
	std::cout << ")";
}

Expression* ExpressionParenthesee::horsParenthese()
{
	return _exprInter->horsParenthese();
}

Expression* ExpressionParenthesee::enleverParentheses()
{
	Expression* retour = _exprInter->enleverParentheses();
	_exprInter = nullptr;
	delete this;
	return retour;
}

void ExpressionParenthesee::ajouterParentheses()
{
	_exprInter->ajouterParentheses();
}

std::unordered_set<Identifiant*> ExpressionParenthesee::getIdentifiants()
{
	return _exprInter->getIdentifiants();
}

std::pair<Expression*, Expression*> ExpressionParenthesee::optimiser(Programme& programme, bool remonter)
{
	std::pair<Expression*, Expression*> paire;
	paire = _exprInter->optimiser(programme, remonter);
	
	return paire;
}

Expression* ExpressionParenthesee::simplifier(Programme& programme)
{
	return _exprInter->simplifier(programme);
}

bool ExpressionParenthesee::estEvaluable(Programme& programme)
{
	return _exprInter->estEvaluable(programme);
}
