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
	Symbole* p_virgule = a->popSymbole();
	Symbole* instruction = a->popSymbole();
	Symbole* instructions = new Instructions(instruction, p_virgule);
	a-> popState();
	a-> popState();
	a->etatCourrant()->transition(a, instruction);
}