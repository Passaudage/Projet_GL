#include <iostream>

#include "etats/Etat15.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "Declaration_var.hpp"

Etat15::Etat15()
{

}

Etat15::~Etat15()
{

}

void Etat15::transition(Automate* a, Symbole* s) //réduction de la règle 2
{
	Symbole* virgule = a->popSymbole();
	Symbole* id = a->popSymbole();
	Symbole* idv = a->popSymbole();
	Symbole* declaration_var = new Declaration_var(idv, id, virgule);
	a-> popState();
	a-> popState();
	a->popState();
	a->etatCourrant()->transition(a, declaration_var);
}