#include "symboles/ExpressionMultiplication.hpp"
#include "symboles/Valeur.hpp"

#include <iostream>

#include "symboles/ExpressionDivision.hpp"

ExpressionMultiplication::ExpressionMultiplication(
		Expression& exprGauche,
		Expression& exprDroite
	):ExpressionBinaire(exprGauche, exprDroite, true, 1, Symbole::Type::OPERATEUR_MUL)
{
}

void ExpressionMultiplication::afficher()
{
	_exprGauche->afficher();
	std::cout << "*";
	_exprDroite->afficher();
}

int ExpressionMultiplication::operation(int a, int b, bool oppose)
{
	if(oppose) {
		return a / b;
	}
	return a * b;
}

ExpressionBinaire* ExpressionMultiplication::construireExpression(
	Expression* exprGauche, Expression* exprDroite, bool oppose)
{
	if(oppose) {
		return new ExpressionDivision(*exprGauche, *exprDroite); 
	}

	return new ExpressionMultiplication(*exprGauche, *exprDroite);
}

Expression* ExpressionMultiplication::simplifier(Programme& programme)
{
	Expression* expr = simplifierElementNeutre(programme);

	if(expr != this) {
		return expr;
	}

	if((_exprDroite->estEvaluable(programme) &&
		_exprDroite->calculer(programme) == 0) ||
		(_exprGauche->estEvaluable(programme) &&
		_exprGauche->calculer(programme) == 0))  {
		return new Valeur(0);
	}

	return this;
}


/*
Expression* ExpressionMultiplication::optimiser(Programme& programme)
{
	//~ std::cout << "Expression Multiplication optimisation "<<std::endl;
	Expression* left = _exprGauche->optimiser(programme);
	Expression* right = _exprDroite->optimiser(programme);

	if(left->estEvaluable(programme) && right->estEvaluable(programme)) {
		return new Valeur(left->calculer(programme)*right->calculer(programme));
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
		return new ExpressionMultiplication(*left,*right);
	}	
}
*/