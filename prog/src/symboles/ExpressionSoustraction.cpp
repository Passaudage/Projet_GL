#include "symboles/ExpressionSoustraction.hpp"
#include "symboles/Valeur.hpp"

#include <iostream>


int ExpressionSoustraction::calculer(Programme& programme)
{
	return _exprGauche->calculer(programme) - _exprDroite->calculer(programme);
}

ExpressionSoustraction::ExpressionSoustraction(
		Expression& exprGauche,
		Expression& exprDroite
	):ExpressionBinaire(exprGauche, exprDroite)
{
}

void ExpressionSoustraction::afficher()
{
	_exprGauche->afficher();
	std::cout << "-";
	_exprDroite->afficher();
}

Expression* ExpressionSoustraction::optimiser(Programme& programme)
{
	//~ std::cout << "Expression Soustraction optimisation "<<std::endl;
	Expression* left = _exprGauche->optimiser(programme);
	Expression* right = _exprDroite->optimiser(programme);

	if(left->estEvaluable(programme) && right->estEvaluable(programme)) {
		return new Valeur(left->calculer(programme)-right->calculer(programme));
	}
	else {
		if(left->estEvaluable(programme)) {
			if(left->calculer(programme) == 0) {
				return right;
			}
		}
		else if(right->estEvaluable(programme)) {
			if(right->calculer(programme) == 0) {
				return left;
			}
		}
		return new ExpressionSoustraction(*left,*right);
	}
}