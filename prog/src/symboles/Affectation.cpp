#include "symboles/Affectation.hpp"

void Affectation::effectuer(Programme& programme) {
	programme.setValeur(_identifiant.get(), _expr.calculer(programme));	
}

Affectation::Affectation(Expression& expr, Identifiant& identifiant) : 
	InstructionExpression(expr),_identifiant(identifiant)
{
}

Affectation::~Affectation(){
	delete &_identifiant;
}
