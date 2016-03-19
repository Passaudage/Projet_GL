#include <iostream>

#include "etats/Etat36.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/Instructions.hpp"
#include "symboles/Instruction.hpp"

Etat36 Etat36::m_instance = Etat36();

Etat36::Etat36()
{
}

Etat36* Etat36::getInstance(){
	return &m_instance;
}


void Etat36::transition(Automate* a, Symbole* ) 
{
	// OK
#ifdef MAP
	std::cout << "Etat36" << std::endl;
#endif

	// récupération de Instruction
	Instruction* instruction = dynamic_cast<Instruction*> (a->popSymbole());
	Instructions* instructions = dynamic_cast<Instructions*> (a->symboleCourant());

	instructions->ajouteInstruction(instruction);

	a->popEtat();
	a->popEtat();
	a->popEtat();
	a->etatCourant()->transition(a, instructions);
}
