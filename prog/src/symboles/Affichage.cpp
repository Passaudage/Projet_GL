#include "symboles/Affichage.hpp"
#include <iostream>

const std::string Affichage::_keyword = "ecrire";

void Affichage::afficher()
{
	std::cout << _keyword << ' ';
	_expr.afficher();
	std::cout << ';' << std::endl;
}

void Affichage::effectuer(Programme& programme)
{
	std::cout << _expr.calculer(programme) << std::endl;
}

Affichage::Affichage(Expression& expr) : InstructionExpression(expr)
{
}
