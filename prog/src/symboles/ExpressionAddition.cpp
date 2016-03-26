#include "symboles/ExpressionAddition.hpp"
#include "symboles/Valeur.hpp"

#include <iostream>

#include "symboles/ExpressionSoustraction.hpp"

ExpressionAddition::ExpressionAddition(
		Expression& exprGauche,
		Expression& exprDroite
	):ExpressionBinaire(exprGauche, exprDroite, true, 0, Symbole::Type::OPERATEUR_ADD)
{
}

void ExpressionAddition::afficher()
{
	_exprGauche->afficher();

	// permet d'éviter l'affichage "variable+-50"
	if(!(_exprDroite->getInitType() == Symbole::Type::VALEUR &&
		((Valeur*)_exprDroite)->getValeur() < 0)) {
		std::cout << "+";
	}
	
	_exprDroite->afficher();
}

int ExpressionAddition::operation(int a, int b, bool oppose)
{
	if(oppose) {
		return a - b;
	}

	return a + b;
}

ExpressionBinaire* ExpressionAddition::construireExpression(
	Expression* exprGauche, Expression* exprDroite, bool oppose)
{
	if(!oppose) {
		return new ExpressionAddition(*exprGauche, *exprDroite);
	}

	return new ExpressionSoustraction(*exprGauche, *exprDroite);
}

Expression* ExpressionAddition::simplifier(Programme& programme)
{
	Expression* expr = simplifierElementNeutre(programme);

	if(expr != this) {
		return expr;
	}

	return this;
}


/*
Expression* ExpressionAddition::optimiser(Programme& programme)
{
	std::cout << "Expression Addition optimisation "<<std::endl;
	
	Expression* left = _exprGauche->optimiser(programme);
	Expression* right = _exprDroite->optimiser(programme);

	left->afficher();
	std::cout << std::endl;

	int valeur = 0;

	if(int(*right) == Symbole::Type::TERME) {
		std::cout << "Operateur Add" << std::endl;
		// ici on est certain que l'expression à droite est aussi une addition
		// il faut : récupérer la somme des constantes, les supprimer de la sous-expression 

		std::pair<Expression*, int> left_pair = left->optimiser_reduire(programme);

		valeur += left_pair.second;
		left = left_pair.first;

		return ExpressionAddition(*left, *right);
	}

	if(left->estEvaluable(programme) && right->estEvaluable(programme)) {
		return new Valeur(left->calculer(programme) + right->calculer(programme));
	} else {
		if(left->estEvaluable(programme)) {
			if(left->calculer(programme) == 0) {
				return right;
			}
		} else if(right->estEvaluable(programme)) {
			if(right->calculer(programme) == 0) {
				return left;
			}
		}
		return new ExpressionAddition(*left, *right);
	}

}

std::pair<Expression*, int> ExpressionAddition::optimiserReduire(Programme& programme)
{
	// détection d'une ou de deux constantes

	int valeur = 0;
	Expression* exprGauche, exprDroite;

	if(int(*_exprGauche) == int(*this)) {
		std::pair<Expression*, int> pairGauche = _exprGauche->optimiser_reduire();
		exprGauche = pairGauche.first;
		valeur = operation(valeur, pairGauche.second);
	} else {
		exprGauche = _exprGauche->optimiser();
	}

	if(int(*_exprDroite) == int(*this)) {
		std::pair<Expression*, int> pairDroite = _exprDroite->optimiser_reduire();
		exprDroite = pairDroite.first;
		valeur = operation(valeur, pairDroite.second);
	} else {
		exprDroite = _exprDroite->optimiser();
	}


	// optimiser_
	if((int(*exprGauche) == Symbole::Type::CONSTANTE) &&
		(int(*exprDroite) == Symbole::Type::CONSTANTE)) {
		// les deux côtés sont des constantes
		// simplifions !

		int valeurGauche = exprGauche->calculer();
		int valeurDroite = exprDroite->calculer();

		return new Valeur(valeurGauche + valeurDroite);
	}
	
	std::pair<Expression*, int> pairExpression;

	// optimiser_reduire
	if(int(*exprGauche) == Symbole::Type::CONSTANTE) {
		// le côté gauche est une constante
		// simplifions le !
		int valeurGauche = exprGauche->calculer();

		// traitement des éléments neutres
		if(_commutatif && (valeurGauche == _element_neutre)) {
			pairExpression.first = exprDroite;
			pairExpression.second = 0;

			return pairExpression;
		}
	}

	if(int(*exprDroite) == Symbole::Type::CONSTANTE) {
		// le côté droit est une constante
		// simplifions le !
		int valeurDroite = exprDroite->calculer();

		// traitement des éléments neutres
		if(valeurDroite == _element_neutre) {
			return exprGauche;
		}
	}


	

}
*/