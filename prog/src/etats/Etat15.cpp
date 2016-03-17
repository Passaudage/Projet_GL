#include <iostream>

#include "etats/Etat15.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/Declaration_var.hpp"

Etat15::Etat15()
{

}

Etat15::~Etat15()
{

}

void Etat15::transition(Automate* a, Symbole* s) //réduction de la règle 2
{
	a->popSymbole();
	Symbole* id = (Identifiant*) a->popSymbole();
	Symbole* idv = (IDV*) a->popSymbole();
	idv->ajouterVariable(id->get());
	a-> popEtat();
	a-> popEtat();
	a->popEtat();
	a->etatCourant()->transition(a, declaration_var);
}
