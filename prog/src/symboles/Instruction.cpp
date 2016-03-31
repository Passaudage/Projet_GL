#include "symboles/Instruction.hpp"

#include "symboles/Identifiant.hpp"
#include <iostream>

Instruction::Instruction():Symbole(Symbole::Type::INSTRUCTION)
{
}

Instruction::~Instruction()
{
}

void Instruction::optimiser(Programme&)
{
	// Comportement par défaut : ne pas optimiser
}

