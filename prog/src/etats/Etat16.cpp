#include <iostream>

#include "etats/Etat16.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat16bis.hpp"

Etat16 Etat16::m_instance = Etat16();

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
			//~ a->pushEtat(new Etat16bis());
			a->pushEtat(Etat16bis::getInstance());
			a->decaler();
			break;
		default:
			throw "Erreur, lecture non conforme à la grammaire ! "; 
			break;
	}
}
