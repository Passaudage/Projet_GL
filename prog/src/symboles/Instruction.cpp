#include "symboles/Instruction.hpp"

#include "symboles/Identifiant.hpp"
#include <iostream>

std::unordered_set<Identifiant*> const& Instruction::getVarUtilisees()
{
	return _varUtilisees;
}

std::unordered_set<Identifiant*> const& Instruction::getVarAffectees()
{
	return _varAffectees;
}

Instruction::Instruction():Symbole(Symbole::Type::INSTRUCTION)
{
}

Instruction::~Instruction()
{
}

void Instruction::optimiser(Programme& programme)
{
	// Comportement par défaut : ne pas optimiser
}

