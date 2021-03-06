#include <iostream>

#include "etats/Etat35.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat36.hpp"

#include "Erreurs.hpp"

Etat35 Etat35::m_instance;

Etat35::Etat35()
{
}

Etat35* Etat35::getInstance(){
	return &m_instance;
}


void Etat35::transition(Automate* a, Symbole* s)
{
	// OK
#ifdef MAP
	std::cout << "Etat35" << std::endl;
#endif
    switch(*s){
		case Symbole::POINT_VIR:
			a->pushEtat(Etat36::getInstance());
			a->decaler();
			break;
		default:
			a->pushEtat(Etat36::getInstance());
			break;
	}
}
