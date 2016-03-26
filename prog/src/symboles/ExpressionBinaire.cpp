#include "symboles/ExpressionBinaire.hpp"

#include <iostream>

#include "symboles/Identifiant.hpp"

#include "symboles/ExpressionParenthesee.hpp"
#include "symboles/ExpressionAddition.hpp"
#include "symboles/Valeur.hpp"

ExpressionBinaire::ExpressionBinaire(Expression& exprGauche, Expression& exprDroite,
	bool commutatif, int element_neutre, Symbole::Type operation):
	Expression(FACTEUR), _commutatif(commutatif), _element_neutre(element_neutre),
	_operation(operation)
{
	_exprDroite = &exprDroite;
	_exprGauche = &exprGauche;
}

ExpressionBinaire::~ExpressionBinaire()
{
	delete &_exprDroite;
	delete &_exprGauche;
}

int ExpressionBinaire::calculer(Programme& programme)
{
	return operation(_exprGauche->calculer(programme),
		_exprDroite->calculer(programme));
}

std::unordered_set<Identifiant*> ExpressionBinaire::getIdentifiants()
{
	std::unordered_set<Identifiant*> set_a = _exprGauche->getIdentifiants();
	std::unordered_set<Identifiant*> set_b = _exprDroite->getIdentifiants();

	set_a.insert(set_b.begin(), set_b.end());

	return set_a;
}

bool ExpressionBinaire::estEvaluable(Programme& programme)
{
	return _exprDroite->estEvaluable(programme) && _exprGauche->estEvaluable(programme);
}

Symbole::Type ExpressionBinaire::getOperation()
{
	return _operation;
}

Expression* ExpressionBinaire::enleverParentheses()
{
#ifdef MAP
	std::cout << "enleverParentheses:";
	this->afficher();
	std::cout << std::endl;
#endif

	Expression* exprGauche = _exprGauche->horsParenthese();
	Expression* exprDroite = _exprDroite->horsParenthese();

	ExpressionBinaire* exprBinaireGauche = dynamic_cast<ExpressionBinaire*>(exprGauche);
	ExpressionBinaire* exprBinaireDroite = dynamic_cast<ExpressionBinaire*>(exprDroite);

	if(exprBinaireGauche != nullptr &&
		(exprBinaireGauche->getOperation() == this->getOperation())) {
#ifdef MAP
		std::cout << "On peut simplifier à gauche !" << std::endl;
#endif

		//_exprGauche = new ExpressionParenthesee(*(_exprGauche->enleverParentheses()));
		_exprGauche = _exprGauche->enleverParentheses();

		// memleak
	}

	if(exprBinaireDroite != nullptr &&
		(exprBinaireDroite->getOperation() == this->getOperation())) {

#ifdef MAP
		std::cout << "On peut simplifier à droite !" << std::endl;
#endif

		exprBinaireDroite->enleverParentheses();

		/*
		Expression* interieur = new ExpressionParenthesee(*(construireExpression(
			_exprGauche, exprBinaireDroite->getGauche())));

		Expression* exterieur = new ExpressionParenthesee(*(exprBinaireDroite->construireExpression(
			interieur, exprBinaireDroite->getDroite(), oppose)));
		*/

		Expression* interieur = (construireExpression(
			_exprGauche, exprBinaireDroite->getGauche()));
		Expression* exterieur = (exprBinaireDroite->construireExpression(
			interieur, exprBinaireDroite->getDroite(), !_commutatif));

		return exterieur->enleverParentheses();
	} else {
		if(_exprDroite->getInitType() != Symbole::Type::VALEUR) {
			//_exprDroite = new ExpressionParenthesee(*exprDroite->enleverParentheses());
			_exprDroite = exprDroite->enleverParentheses();
		} else
			_exprDroite = exprDroite->enleverParentheses();
	}

	return this;
}

bool ExpressionBinaire::commutatif()
{
	return _commutatif;
}

Expression* ExpressionBinaire::getGauche()
{
	return _exprGauche;
}

Expression* ExpressionBinaire::getDroite()
{
	return _exprDroite;
}


std::pair<Expression*, Expression*> ExpressionBinaire::optimiser(Programme& programme, bool remonter)
{
	bool gauche = false;
	bool droite = false;

#ifdef MAP
	std::cout << "optimiser";
	if(remonter)
		std::cout << "- remonter";
	std::cout << " ~";
	afficher();
	std::cout << "~" << std::endl;
#endif

	std::pair<Expression*, Expression*> paireResultat;

	if(_exprDroite->estEvaluable(programme)) {
		_exprDroite = new Valeur(_exprDroite->calculer(programme));
		droite = true;
	}

	if(_exprGauche->estEvaluable(programme)) {
		_exprGauche = new Valeur(_exprGauche->calculer(programme));
		gauche = true;
	}

	if(gauche && droite) {
		//std::cout << "=> deux constantes" << std::endl;
		paireResultat.first = new Valeur(
			operation(_exprGauche->calculer(programme), _exprDroite->calculer(programme)));
		
		paireResultat.second = nullptr;

		return paireResultat;
	}

	//std::pair<Expression*, Expression*> paireDroite;
	std::pair<Expression*, Expression*> paireGauche;

	// optimisation de la partie de droite
	if(!droite) {
#ifdef MAP
		std::cout << "=> expr a droite, on optimise" << std::endl;
#endif
		_exprDroite = _exprDroite->optimiser(programme).first;
		_exprDroite = _exprDroite->simplifier(programme);
	}
	
	// puis de la partie de gauche
	if(!gauche) {

#ifdef MAP
		std::cout << "=> expr a gauche, ";
#endif

		if(!_exprDroite->estEvaluable(programme)) {
#ifdef MAP
			std::cout << "expr a droite" << std::endl;
#endif
			// on ne peut pas faire remonter l'information
			_exprGauche = _exprGauche->optimiser(programme).first;
			_exprGauche = _exprGauche->simplifier(programme);

		} else {
			// l'expression de droite est évaluable donc on peut
			// faire potentiellement remonter des informations
			// si les opérateurs correspondent
#ifdef MAP
			std::cout << "constante a droite" << std::endl;
			afficher();
			std::cout << std::endl;
#endif

			// vérification des opérateurs

			ExpressionBinaire* exprBinaireGauche =
				dynamic_cast<ExpressionBinaire*>(_exprGauche->horsParenthese());

			if(exprBinaireGauche != nullptr && exprBinaireGauche->getOperation() == getOperation()) {
				// on peut faire remonter l'information

				paireGauche = _exprGauche->optimiser(programme, true);
				/*
				std::cout << "Je viens d'optimiser :";
				_exprGauche->afficher();
				std::cout << std::endl;
*/
				paireGauche.first = paireGauche.first->simplifier(programme);

				if(paireGauche.second != nullptr) {
/*
					paireGauche.first->afficher();
					std::cout << std::endl;
					paireGauche.second->afficher();
					std::cout << std::endl << "dans :";
					afficher();
					std::cout << std::endl;
*/
					Expression* tempExprDroite = construireExpression(paireGauche.second, _exprDroite);

					tempExprDroite = tempExprDroite->optimiser(programme).first;

					// Donne forcément l'opérateur commutatif correspondant
					ExpressionBinaire* globalExpr = construireExpression(paireGauche.first, tempExprDroite,
						!_commutatif);

					globalExpr = (ExpressionBinaire*) globalExpr->enleverParentheses();
					globalExpr = (ExpressionBinaire*) globalExpr->simplifier(programme);

#ifdef MAP
					std::cout << "Apres avoir enlever les parentheses" << std::endl;
					globalExpr->afficher();
					std::cout << std::endl;
#endif

					if(remonter && estValeurConstante(globalExpr->getDroite(), programme)) {
						// on peut remonter l'information

						paireResultat.first = globalExpr->getGauche();
						if(!globalExpr->commutatif())
							paireResultat.second = construireExpression(
								new Valeur(_element_neutre), globalExpr->getDroite())->simplifier(programme);
						else
							paireResultat.second = globalExpr->getDroite();

						return paireResultat;
					}

					paireResultat.first = globalExpr;
					paireResultat.second = nullptr;

					return paireResultat;
				}

			} else {
				// on a variable à gauche, constante à droite

				if(remonter) {
					paireResultat.first = _exprGauche;

					if(!_commutatif) {
						paireResultat.second = construireExpression(
							new Valeur(_element_neutre), _exprDroite)->simplifier(programme);
					} else {
						paireResultat.second = _exprDroite;
					}	
				} else {
					this->simplifier(programme);
					paireResultat.first = this;
					paireResultat.second = nullptr;
				}
				
				return paireResultat;
			}
		}
	}

	if(!_exprDroite->estEvaluable(programme)) {
		// On a une valeur/constante à gauche
#ifdef MAP
		std::cout << "=> constante a gauche, expr a droite" << std::endl;
#endif

		int valeurGauche = _exprGauche->calculer(programme);

		if(valeurGauche == _element_neutre && !_commutatif) {
			// 0-var
			// 1/var
			paireResultat.first = this;
			paireResultat.second = nullptr;
			return paireResultat;
		}

		if(remonter) {
			// on remonte les infos
			// on doit inverse les cotes

			Expression* newExprGauche = _exprDroite;

			if(!_commutatif) {
				newExprGauche = construireExpression(
					new Valeur(_element_neutre), _exprDroite)->simplifier(programme);
			}

			paireResultat.first = newExprGauche;
			paireResultat.second = _exprGauche;

			return paireResultat;
		}

		paireResultat.first = this;
		paireResultat.second = new Valeur(_element_neutre);
		return paireResultat;
		
	}

	// Check si constantes !!

	if(_exprDroite->estEvaluable(programme)) {
		_exprDroite = new Valeur(_exprDroite->calculer(programme));
		droite = true;
	}

	if(_exprGauche->estEvaluable(programme)) {
		_exprGauche = new Valeur(_exprGauche->calculer(programme));
		gauche = true;
	}

	if(gauche && droite) {
#ifdef MAP
		std::cout << "=> deux constantes" << std::endl;
#endif

		paireResultat.first = new Valeur(
			operation(_exprGauche->calculer(programme), _exprDroite->calculer(programme)));
		
		paireResultat.second = nullptr;

		return paireResultat;
	}

	paireResultat.first = this;
	paireResultat.second = nullptr;

	return paireResultat;
}

bool ExpressionBinaire::estValeurConstante(Expression* expr, Programme& programme)
{
	if(expr->getInitType() == Symbole::Type::VALEUR ||
		(expr->getInitType() == Symbole::Type::IDENTIFIANT &&
			!programme.estModifiable(((Identifiant*)expr)->get())))
		return true;

	return false;
}

Expression* ExpressionBinaire::simplifierElementNeutre(Programme& programme)
{
	if(_commutatif) {
		if(_exprGauche->estEvaluable(programme) && 
			_exprGauche->calculer(programme) == _element_neutre)
			return _exprDroite;
	}

	if(_exprDroite->estEvaluable(programme) && 
		_exprDroite->calculer(programme) == _element_neutre)
		return _exprGauche;

	return this;
}
