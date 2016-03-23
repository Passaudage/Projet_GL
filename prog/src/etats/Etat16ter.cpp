#include <iostream>
#include "etats/Etat16ter.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat17.hpp"

#include "Erreurs.hpp"

Etat16ter Etat16ter::m_instance = Etat16ter();

Etat16ter::Etat16ter()
{
}

Etat16ter* Etat16ter::getInstance(){
	return &m_instance;
}


void Etat16ter::transition(Automate* a, Symbole* s)
{
#ifdef MAP
	std::cout << "Etat16ter" << std::endl;
#endif
     switch(*s){
		case Symbole::VALEUR:
			a->pushSymbole(s);
			//~ a->pushEtat(new Etat17());
			a->pushEtat(Etat17::getInstance());
			a->decaler();
			break;
		default:
			throw ExceptionSymbole(s, ExceptionSymbole::symbole_non_attendu);
			break;
	}
}
