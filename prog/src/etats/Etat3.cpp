#include <iostream>

#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat3.hpp"
#include "etats/Etat12.hpp"
#include "symboles/Declarations.hpp"

#include "Erreurs.hpp"

Etat3 Etat3::m_instance = Etat3();

Etat3::Etat3()
{
}

Etat3* Etat3::getInstance(){
	return &m_instance;
}


void Etat3::transition(Automate* a, Symbole* s)
{
	// Tout OK
#ifdef MAP
	std::cout << "Etat3" << std::endl;
#endif
	switch(*s){
		case Symbole::DECLARATION_VAR:
		// OK
			//~ a->pushEtat(new Etat12());
			a->pushEtat(Etat12::getInstance());
			break;
		case Symbole::IDENTIFIANT:
		// OK
			{
				Declarations::IDV* idv = new Declarations::IDV();
				a->pushSymbole(idv);
				a->etatCourant()->transition(a, idv);
			}
			break;
		default:
			throw ExceptionSymbole(s, ExceptionSymbole::symbole_non_attendu);
		break;
	}
}
