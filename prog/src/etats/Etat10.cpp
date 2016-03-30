#include <iostream>

#include "etats/Etat10.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat11.hpp"

#include "Erreurs.hpp"

Etat10 Etat10::m_instance;

Etat10::Etat10()
{
}

Etat10* Etat10::getInstance(){
	return &m_instance;
}


void Etat10::transition(Automate* a, Symbole* s)
{
#ifdef MAP
	std::cout << "Etat10" << std::endl;
#endif
	switch(*s){
		case Symbole::POINT_VIR:
			//~ a->pushEtat(new Etat11());
			a->pushEtat(Etat11::getInstance());
			a->decaler();
			break;
		default:
			throw ExceptionSymbole(s, ExceptionSymbole::symbole_non_attendu);
			break;
	}
}
