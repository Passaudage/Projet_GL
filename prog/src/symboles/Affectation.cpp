#include "symboles/Affectation.hpp"
#include <iostream>

const std::string Affectation::_keyword = ":=";

void Affectation::afficher()
{
	std::cout << _identifiant.get() << ' ' << _keyword << ' ';
	_expr->afficher();
	std::cout << ';' << std::endl;
}

void Affectation::effectuer(Programme& programme)
{
	programme.setValeur(_identifiant.get(), _expr->calculer(programme));	
}

Affectation::Affectation(Expression& expr, Identifiant& identifiant) : 
	InstructionExpression(expr),
	_identifiant(identifiant)
{
}

Affectation::~Affectation()
{
	delete &_identifiant;
}

void Affectation::optimiser(Programme& programme)
{
	_expr = _expr->enleverParentheses()->
		optimiser(programme).first->
		simplifier(programme);
	_expr->ajouterParentheses();
	if (_expr->estEvaluable(programme)) {
		programme.rendPropre(_identifiant.get());
		programme.setValeur(_identifiant.get(), _expr->calculer(programme));
	} else {
		programme.rendSale(_identifiant.get());
	}
}

Identifiant const * Affectation::getVarAffectees()
{
	return &_identifiant;
}

bool Affectation::estSansEffet()
{
	std::unordered_set<Identifiant*> set = _expr->getIdentifiants();
	if (set.size() != 1)
		return false;

	Identifiant* id = *(set.begin());

	if (id->get() != _identifiant.get()) {
		return false;
	} 

	//Teste si l'expression est l'id simple;
	if (_expr->getInitType() != Symbole::IDENTIFIANT)
		return false;

	return true;
	
}
