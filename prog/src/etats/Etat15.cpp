#include <iostream>

#include "etats/Etat15.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/Declarations.hpp"
#include "symboles/Identifiant.hpp"

Etat15::Etat15()
{

}

Etat15::~Etat15()
{

}

void Etat15::transition(Automate* a, Symbole* ) //réduction de la règle 2
{
	// Tout OK
#ifdef MAP
	std::cout << "Etat15" << std::endl;
#endif

	Identifiant* id = dynamic_cast<Identifiant*> (a->popSymbole());
	Declarations::IDV* idv = dynamic_cast<Declarations::IDV*> (a->popSymbole());
	
	idv->ajouterVariable(id->get());
	
	a->popEtat();
	a->popEtat();
	a->popEtat();

	a->etatCourant()->transition(a, idv);
}
