#include <iostream>
#include "symboles/Affichage.hpp"
#include <iostream>

const std::string Affichage::_keyword = "ecrire";
std::unordered_set<Affichage*> Affichage::affichages;



void Affichage::afficher()
{
	std::cout << _keyword << ' ';
	_expr->afficher();
	std::cout << ';' << std::endl;
}

void Affichage::effectuer(Programme& programme)
{
	std::cout << _expr->calculer(programme) << std::endl;
}

Affichage::Affichage(Expression& expr) : InstructionExpression(expr)
{
	affichages.insert(this);
}

Affichage::~Affichage()
{
	affichages.erase(this);
}

void Affichage::optimiser(Programme& programme)
{
	_expr = _expr->enleverParentheses()->
		optimiser(programme).first->
		simplifier(programme);
	_expr->ajouterParentheses();
}

std::unordered_set<Affichage*> const & Affichage::getAffichages()
{
	return affichages;
}

Identifiant const * Affichage::getVarAffectees()
{
	return nullptr;	
}
