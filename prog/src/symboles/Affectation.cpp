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
}

Identifiant const * Affectation::getVarAffectees()
{
	return &_identifiant;
}
