#include <iostream>

#include "etats/Etat6.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/Declarations.hpp"

Etat14::Etat14()
{

}

Etat14::~Etat14()
{

}

void Etat14::transition(Automate* a, Symbole* s) //réduction de la règle 6
{
	a->popSymbole();
	Symbole* id = (Identifiant*) a->popSymbole();
	Symbole* idv = (IDV*) a->popSymbole();
	a->popSymbole();
	Symbole* d = a->popSymbole();
	d->ajouterVariable(id->get());
	d->enregistrerVariables(idv);
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a->etatCourant()->transition(a, lecturedeclarations);
}
