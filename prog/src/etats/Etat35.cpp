#include <iostream>

#include "etats/Etat35.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat36.hpp"

Etat35::Etat35()
{
    //ctor
}

void Etat35::transition(Automate* a, Symbole* s)
{
	// OK
#ifdef MAP
	std::cout << "Etat35" << std::endl;
#endif
    switch(*s){
		case Symbole::POINT_VIR:
			a->pushEtat(new Etat36());
			a->decaler();
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
	}
}
