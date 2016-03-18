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
	a->popSymbole();
	Instruction* instruction = (Instruction*) a->popSymbole();
	Instructions* instructions = (Instructions*) a->popSymbole();
	instructions->ajouteInstruction(instruction);

	a->popEtat();
	a->popEtat();
	a->popEtat();
	a->etatCourant()->transition(a, instructions);
}
