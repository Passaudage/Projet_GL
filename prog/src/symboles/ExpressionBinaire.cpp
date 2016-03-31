#include "symboles/ExpressionBinaire.hpp"

#include <iostream>

#include "symboles/Identifiant.hpp"

#include "symboles/ExpressionParenthesee.hpp"
#include "symboles/ExpressionAddition.hpp"
#include "symboles/Valeur.hpp"

ExpressionBinaire::ExpressionBinaire(Expression& exprGauche, Expression& exprDroite,
	bool commutatif, int element_neutre, Symbole::Type operation):
	Expression(FACTEUR), _commutatif(commutatif), _element_neutre(element_neutre),
	_operation(operation), _uneFois(false)
{
	_exprDroite = &exprDroite;
	_exprGauche = &exprGauche;
}

ExpressionBinaire::~ExpressionBinaire()
{
	if(_exprDroite != nullptr)
		delete _exprDroite;

	if(_exprGauche != nullptr)
		delete _exprGauche;
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

void ExpressionBinaire::invaliderExpression()
{
	_exprDroite = _exprGauche = nullptr;
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

		// memleak ?
	}

	if(exprBinaireDroite != nullptr &&
		(exprBinaireDroite->getOperation() == this->getOperation())) {

#ifdef MAP
		std::cout << "On peut simplifier à droite !" << std::endl;
#endif

		exprBinaireDroite->enleverParentheses();

		Expression* interieur = (construireExpression(
			_exprGauche, exprBinaireDroite->getGauche()));
		Expression* exterieur = (exprBinaireDroite->construireExpression(
			interieur, exprBinaireDroite->getDroite(), !_commutatif));

		return exterieur->enleverParentheses();
	} else {
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


void ExpressionBinaire::ajouterParentheses()
{
	ExpressionBinaire* exprBinaireGauche;
	ExpressionBinaire* exprBinaireDroite;

	exprBinaireGauche = dynamic_cast<ExpressionBinaire*>(_exprGauche);
	exprBinaireDroite = dynamic_cast<ExpressionBinaire*>(_exprDroite);

	if(_operation == Symbole::Type::OPERATEUR_MUL) {
		if(exprBinaireGauche != nullptr &&
			exprBinaireGauche->getOperation() == Symbole::Type::OPERATEUR_ADD) {
			_exprGauche = new ExpressionParenthesee(*_exprGauche);
		}
		if(exprBinaireDroite != nullptr &&
			exprBinaireDroite->getOperation() == Symbole::Type::OPERATEUR_ADD) {
			_exprDroite = new ExpressionParenthesee(*_exprDroite);
		}
	}

	_exprGauche->ajouterParentheses();
	_exprDroite->ajouterParentheses();
}

std::pair<Expression*, Expression*> ExpressionBinaire::optimiser(
		Programme& programme, bool remonter)
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

	paireResultat.first = nullptr;
	paireResultat.second = nullptr;

	Expression* exprDroite;
	Expression* exprGauche;

	if(_exprDroite->estEvaluable(programme)) {
		exprDroite = new Valeur(_exprDroite->calculer(programme));

		delete _exprDroite;
		_exprDroite = exprDroite;

		droite = true;
	}

	if(_exprGauche->estEvaluable(programme)) {
		exprGauche = new Valeur(_exprGauche->calculer(programme));

		delete _exprGauche;
		_exprGauche = exprGauche;

		gauche = true;
	}

	if(gauche && droite) {
		paireResultat.first = new Valeur(
			operation(
				_exprGauche->calculer(programme), _exprDroite->calculer(programme)
				));
		
		paireResultat.second = nullptr;

		delete this;
		return paireResultat;
	}

	std::pair<Expression*, Expression*> paireGauche;

	// optimisation de la partie de droite
	if(!droite) {
#ifdef MAP
		std::cout << "=> expr a droite, on optimise" << std::endl;
#endif
		_exprDroite = _exprDroite->optimiser(programme).first->
			simplifier(programme);
	}
	
	// puis de la partie de gauche
	if(!gauche) {

#ifdef MAP
		std::cout << "=> expr a gauche, ";
#endif

		if(!droite) {
#ifdef MAP
			std::cout << "expr a droite" << std::endl;
#endif
			if(remonter) {
				paireResultat = _exprGauche->optimiser(programme, true);

				if(!paireResultat.second->estEvaluable(programme))
					paireResultat.second = nullptr;

				_exprGauche = paireResultat.first->simplifier(programme);
			} else {
				// on ne peut pas faire remonter l'information
				_exprGauche = _exprGauche->optimiser(programme).first->
					simplifier(programme);
			}

			// réoptimisation si besoin est
			if(!_uneFois) {
				_uneFois = true;

				Expression* valeur = paireResultat.second;

				paireResultat = enleverParentheses()->optimiser(programme);

				paireResultat.first = paireResultat.first->simplifier(programme);

				if(remonter) {
					paireResultat.second = valeur;
				}

				return paireResultat;
			} else {
				_uneFois = false;
			}

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

			_exprGauche = _exprGauche->simplifier(programme);

			ExpressionBinaire* exprBinaireGauche =
				dynamic_cast<ExpressionBinaire*>(_exprGauche->horsParenthese());

			if(exprBinaireGauche != nullptr && exprBinaireGauche->getOperation() == getOperation()) {
				// on peut faire remonter l'information

				paireGauche = _exprGauche->optimiser(programme, true);

				paireGauche.first = paireGauche.first->simplifier(programme);

				if(paireGauche.second != nullptr) {

					Expression* tempExprDroite = 
						construireExpression(paireGauche.second, _exprDroite)->
						optimiser(programme).first;

					// Donne forcément l'opérateur commutatif correspondant
					ExpressionBinaire* globalExpr = construireExpression(paireGauche.first, tempExprDroite,
						!_commutatif);

					globalExpr = (ExpressionBinaire*) globalExpr->enleverParentheses();
					globalExpr = (ExpressionBinaire*) globalExpr->simplifier(programme);

#ifdef MAP
					std::cout << "Apres avoir enlevé les parentheses" << std::endl;
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

						invaliderExpression();

						delete this;
						return paireResultat;
					}

					paireResultat.first = globalExpr;
					paireResultat.second = nullptr;

					invaliderExpression();
					delete this;

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
					invaliderExpression();
					delete this;
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
			// on doit inverse les côtés

			Expression* newExprGauche = _exprDroite;

			if(!_commutatif) {
				newExprGauche = construireExpression(
					new Valeur(_element_neutre), _exprDroite)->simplifier(programme);
			}

			paireResultat.first = newExprGauche;
			paireResultat.second = _exprGauche;

			invaliderExpression();

			return paireResultat;
		}

		paireResultat.first = this;
		paireResultat.second = nullptr;
		return paireResultat;
		
	}

	// Check si constantes !!

	if(_exprDroite->estEvaluable(programme)) {
		exprDroite = new Valeur(_exprDroite->calculer(programme));

		delete _exprDroite;
		_exprDroite = exprDroite;

		droite = true;
	}

	if(_exprGauche->estEvaluable(programme)) {
		exprGauche = new Valeur(_exprGauche->calculer(programme));

		delete _exprGauche;
		_exprGauche = exprGauche;

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
