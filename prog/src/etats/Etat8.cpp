#include <iostream>

#include "etats/Etat8.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat9.hpp"

#include "Erreurs.hpp"

Etat8 Etat8::m_instance;

Etat8::Etat8()
{
}

Etat8* Etat8::getInstance(){
	return &m_instance;
}

void Etat8::transition(Automate* a, Symbole* s)
{
#ifdef MAP
	std::cout << "Etat8" << std::endl;
#endif
	
	switch(*s){
		case Symbole::AFFECTATION:
			a->pushEtat(Etat9::getInstance());
			a->decaler();
			break;
		default:
			a->pushEtat(Etat9::getInstance());
			//throw ExceptionSymbole(s, ExceptionSymbole::symbole_non_attendu);
			break;
	}
}
