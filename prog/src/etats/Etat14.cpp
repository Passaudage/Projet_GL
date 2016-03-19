#include <iostream>

#include "etats/Etat14.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/Declarations.hpp"
#include "symboles/Identifiant.hpp"

Etat14::Etat14()
{

}

void Etat14::transition(Automate* a, Symbole* ) //réduction de la règle 6
{
	// OK
	// récupération de l'identifiant
#ifdef MAP
	std::cout << "Etat14" << std::endl;
#endif
	Identifiant* id = dynamic_cast<Identifiant*> (a->popSymbole());
	Declarations::IDV* idv = dynamic_cast<Declarations::IDV*> (a->popSymbole());
	Declarations* d = dynamic_cast<Declarations*> (a->symboleCourant());

	idv->ajouterVariable(id->get());

	d->enregistrerVariables(*idv);
	delete idv;
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a->etatCourant()->transition(a, d);
}
