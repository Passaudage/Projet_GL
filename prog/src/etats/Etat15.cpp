#include <iostream>

#include "etats/Etat15.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/Declarations.hpp"
#include "symboles/Identifiant.hpp"

#include "Erreurs.hpp"

Etat15 Etat15::m_instance = Etat15();

Etat15::Etat15()
{
}

Etat15* Etat15::getInstance(){
	return &m_instance;
}

void Etat15::transition(Automate* a, Symbole* ) //réduction de la règle 2
{
	// Tout OK
#ifdef MAP
	std::cout << "Etat15" << std::endl;
#endif

	Identifiant* id = dynamic_cast<Identifiant*> (a->popSymbole());
	Declarations::IDV* idv = dynamic_cast<Declarations::IDV*> (a->symboleCourant());
	
	idv->ajouterVariable(id->get());
	delete id;
	
	a->popEtat();
	a->popEtat();
	a->popEtat();

	a->etatCourant()->transition(a, idv);
}
