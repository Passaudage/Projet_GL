#include <iostream>

#include "etats/Etat36.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/Instructions.hpp"
#include "symboles/Instruction.hpp"

Etat36::Etat36()
{
    //ctor
}

Etat36::~Etat36()
{
    //dtor
}
void Etat36::transition(Automate* a, Symbole*) 
{
	// OK
	std::cout << "Etat36" << std::endl;
	
	std::cout << "---> " << Symbole::Type::INSTRUCTION << std::endl;
	std::cout << "---> " << Symbole::Type::INSTRUCTIONS << std::endl;

	// récupération de Instruction

	Instruction* instruction = dynamic_cast<Instruction*> (a->popSymbole());
	Instructions* instructions = dynamic_cast<Instructions*> (a->popSymbole());
	instructions->ajouteInstruction(instruction);

	a->popEtat();
	a->popEtat();
	a->popEtat();
	a->etatCourant()->transition(a, instructions);
}
