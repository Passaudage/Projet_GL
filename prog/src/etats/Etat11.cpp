#include <iostream>

#include "etats/Etat11.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/Instructions.hpp"
#include "symboles/Instruction.hpp"
#include "symboles/Declarations.hpp"

#include "Erreurs.hpp"

Etat11 Etat11::m_instance = Etat11();

Etat11::Etat11()
{
}

Etat11* Etat11::getInstance(){
	return &m_instance;
}


void Etat11::transition(Automate* a, Symbole* ) //réduction de la règle 10
{
#ifdef MAP
	std::cout << "Etat11" << std::endl;
#endif

	Instruction* instruction = dynamic_cast<Instruction*> (a->popSymbole());
	Instructions* instructions = new Instructions();
	instructions->ajouteInstruction(instruction);
	
	a-> popEtat();
	a-> popEtat();
	a->pushSymbole(instructions);
	a->etatCourant()->transition(a, instructions);

}
