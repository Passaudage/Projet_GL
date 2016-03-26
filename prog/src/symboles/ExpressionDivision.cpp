#include "symboles/ExpressionDivision.hpp"
#include "symboles/Valeur.hpp"

#include <iostream>

#include "symboles/ExpressionMultiplication.hpp"

ExpressionDivision::ExpressionDivision(
		Expression& exprGauche,
		Expression& exprDroite
	):ExpressionBinaire(exprGauche, exprDroite, false, 1, Symbole::Type::OPERATEUR_MUL)
{
}

void ExpressionDivision::afficher()
{
	_exprGauche->afficher();
	std::cout << "/";
	_exprDroite->afficher();
}

int ExpressionDivision::operation(int a, int b, bool oppose)
{
	if(oppose) {
		return a * b;
	}
	return a / b;
}

ExpressionBinaire* ExpressionDivision::construireExpression(
	Expression* exprGauche, Expression* exprDroite, bool oppose)
{
	if(!oppose) {
		return new ExpressionDivision(*exprGauche, *exprDroite);
	}

	return new ExpressionMultiplication(*exprGauche, *exprDroite);
}

Expression* ExpressionDivision::simplifier(Programme& programme)
{
	Expression* expr = simplifierElementNeutre(programme);

	if(expr != this) {
		return expr;
	}

	if((_exprGauche->estEvaluable(programme) &&
		_exprGauche->calculer(programme) == 0))  {
		return new Valeur(0);
	}

	return this;
}

/*
Expression* ExpressionDivision::optimiser(Programme& programme)
{
	//~ std::cout << "Expression Division optimisation "<<std::endl;
	Expression* left = _exprGauche->optimiser(programme);
	Expression* right = _exprDroite->optimiser(programme);

	if(left->estEvaluable(programme) && right->estEvaluable(programme)) {
		return new Valeur(left->calculer(programme)/right->calculer(programme));
	}
	else {
		if(left->estEvaluable(programme)) {
			if(left->calculer(programme) == 1) {
				return right;
			}
		}
		else if(right->estEvaluable(programme)) {
			if(right->calculer(programme) == 1) {
				return left;
			}
		}
		return new ExpressionDivision(*left,*right);
	}	
}*/