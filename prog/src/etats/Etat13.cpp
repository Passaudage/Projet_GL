#include <iostream>

#include "etats/Etat13.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat15.hpp"
#include "etats/Etat14.hpp"

Etat13::Etat13()
{

}

Etat13::~Etat13()
{

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
			a->pushEtat(new Etat14());
			a->decaler();
			break;
		case Symbole::VIRGULE:
		// OK
			a->pushEtat(new Etat15());
			a->decaler();
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl; 
			break;
	}
}
