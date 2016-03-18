#include <iostream>

#include "etats/Etat14.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/Declarations.hpp"
#include "symboles/Identifiant.hpp"

Etat14::Etat14()
{

}

Etat14::~Etat14()
{

}

void Etat14::transition(Automate* a, Symbole* s) //réduction de la règle 6
{
	a->popSymbole();
	Identifiant* id = (Identifiant*) a->popSymbole();
	Declarations::IDV* idv = (Declarations::IDV*) a->popSymbole();
	a->popSymbole();
	Declarations* d = (Declarations*) a->popSymbole();
	idv->ajouterVariable(id->get());
	d->enregistrerVariables(*idv);
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a->etatCourant()->transition(a, d);
}
