#include <iostream>

#include "etats/Etat17.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat18.hpp"
#include "etats/Etat19.hpp"

#include "Erreurs.hpp"

Etat17 Etat17::m_instance;

Etat17::Etat17()
{
}

Etat17* Etat17::getInstance(){
	return &m_instance;
}


void Etat17::transition(Automate* a, Symbole* s)
{
	// Tout OK
#ifdef MAP
	std::cout << "Etat17" << std::endl;
#endif
	switch(*s){
		case Symbole::POINT_VIR:
		// OK
			//~ a->pushEtat(new Etat18());
			a->pushEtat(Etat18::getInstance());
			a->decaler();
			break;
		case Symbole::VIRGULE:
		// OK
			//~ a->pushEtat(new Etat19());
			a->pushEtat(Etat19::getInstance());
			a->decaler();
			break;
		default:
			throw ExceptionSymbole(s, ExceptionSymbole::symbole_non_attendu);
			break;
	}
}
