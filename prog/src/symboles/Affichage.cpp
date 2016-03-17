#include "symboles/Affichage.hpp"
#include <iostream>

void Affichage::effectuer(Programme& programme)
{
	std::cout << _expr.calculer(programme) << std::endl;
}

Affichage::Affichage(Expression& expr) : InstructionExpression(expr)
{
}
