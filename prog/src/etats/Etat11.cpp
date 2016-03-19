#include <iostream>

#include "etats/Etat11.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/Instructions.hpp"
#include "symboles/Instruction.hpp"

Etat11::Etat11()
{

}

Etat11::~Etat11()
{

}

void Etat11::transition(Automate* a, Symbole* ) //réduction de la règle 10
{
	std::cout << "Etat11" << std::endl;

	//a->popSymbole();
	Instruction* instruction = dynamic_cast<Instruction*> (a->popSymbole());
	Instructions* instructions = new Instructions();
	instructions->ajouteInstruction(instruction);
	
	a-> popEtat();
	a-> popEtat();
	a->etatCourant()->transition(a, instructions);

}
