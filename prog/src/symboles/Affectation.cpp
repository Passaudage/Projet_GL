#include "Affectation.hpp"

void Affectation::effectuer(Programme& programme) {
	
}

Affectation::Affectation(Expression& expr, Identifiant& identifiant) : 
	InstructionExpression(expr),_identifiant(identifiant)
{
}

Affectation::~Affectation(){
	delete &_identifiant;
}
