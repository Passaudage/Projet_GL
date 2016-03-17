#include <iostream>

#include "etats/Etat11.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "Instructions.hpp"

Etat11::Etat11()
{

}

Etat11::~Etat11()
{

}

void Etat11::transition(Automate* a, Symbole* s) //réduction de la règle 10
{
	a->popSymbole();
	Symbole* instruction = (Instruction*) a->popSymbole();
	Symbole* instructions = new Instructions();
	instructions->ajouteIntruction(instruction);
	a-> popEtat();
	a-> popEtat();
	a->etatCourant()->transition(a, instructions);
}
