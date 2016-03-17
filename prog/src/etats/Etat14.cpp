#include <iostream>

#include "etats/Etat6.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "Declarations.hpp"

Etat14::Etat14()
{

}

Etat14::~Etat14()
{

}

void Etat14::transition(Automate* a, Symbole* s) //réduction de la règle 6
{
	Symbole* p_virgule = a->popSymbole();
	Symbole* id = a->popSymbole();
	Symbole* idv = a->popSymbole();
	Symbole* var = a->popSymbole();
	Symbole* d = a->popSymbole();
	Symbole* declarations = new Declarations(d, var, idv, id, p_virgule);
	a-> popState();
	a-> popState();
	a-> popState();
	a-> popState();
	a-> popState();
	a->etatCourrant()->transition(a, lecturedeclarations);
}