#include "symboles/ExpressionDivision.hpp"
#include "symboles/Valeur.hpp"

#include <iostream>


int ExpressionDivision::calculer(Programme& programme)
{
	return _exprGauche->calculer(programme) / _exprDroite->calculer(programme);
}

ExpressionDivision::ExpressionDivision(
		Expression& exprGauche,
		Expression& exprDroite
	):ExpressionBinaire(exprGauche, exprDroite)
{
}

void ExpressionDivision::afficher()
{
	_exprGauche->afficher();
	std::cout << "/";
	_exprDroite->afficher();
}

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
}