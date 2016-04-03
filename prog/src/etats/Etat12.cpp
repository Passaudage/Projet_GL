#include <iostream>

#include "etats/Etat12.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat13.hpp"

#include "Erreurs.hpp"

Etat12 Etat12::m_instance;

Etat12::Etat12()
{
}

Etat12* Etat12::getInstance(){
	return &m_instance;
}


void Etat12::transition(Automate* a, Symbole* s)
{
	// Tout OK
#ifdef MAP
	std::cout << "Etat12" << std::endl;
#endif
	switch(*s){
		case Symbole::IDENTIFIANT:
		// OK
			a->pushSymbole(s);
			//~ a->pushEtat(new Etat13());
			a->pushEtat(Etat13::getInstance());
			a->decaler();
			break;
		default:
			throw ExceptionSymbole(s, ExceptionSymbole::symbole_non_attendu);
			break;
	}
}
