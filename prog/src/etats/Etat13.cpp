#include <iostream>

#include "etats/Etat13.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat15.hpp"
#include "etats/Etat14.hpp"

#include "Erreurs.hpp"

Etat13 Etat13::m_instance = Etat13();

Etat13::Etat13()
{
}

Etat13* Etat13::getInstance(){
	return &m_instance;
}


void Etat13::transition(Automate* a, Symbole* s)
{
	// Tout OK
#ifdef MAP
	std::cout << "Etat13" << std::endl;
#endif
	switch(*s){
		case Symbole::POINT_VIR:
		// OK
			//~ a->pushEtat(new Etat14());
			a->pushEtat(Etat14::getInstance());
			a->decaler();
			break;
		case Symbole::VIRGULE:
		// OK
			//~ a->pushEtat(new Etat15());
			a->pushEtat(Etat15::getInstance());
			a->decaler();
			break;
		default:
			throw ExceptionSymbole(s, ExceptionSymbole::symbole_non_attendu);
			break;
	}
}
