#include <iostream>

#include "etats/Etat16.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat16bis.hpp"

#include "Erreurs.hpp"

Etat16 Etat16::m_instance;

Etat16::Etat16()
{
}

Etat16* Etat16::getInstance(){
	return &m_instance;
}

void Etat16::transition(Automate* a, Symbole* s)
{
	// Tout OK
#ifdef MAP
	std::cout << "Etat16" << std::endl;
#endif
	switch(*s){
		case Symbole::IDENTIFIANT:
		// OK
			a->pushSymbole(s);
			a->pushEtat(Etat16bis::getInstance());
			a->decaler();
			break;
		default:
			throw ExceptionSymbole(s, ExceptionSymbole::symbole_non_attendu);
			break;
	}
}
