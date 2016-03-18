#include <iostream>

#include "etats/Etat17.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat18.hpp"
#include "etats/Etat19.hpp"

Etat17::Etat17()
{

}

Etat17::~Etat17()
{

}

void Etat17::transition(Automate* a, Symbole* s)
{
	switch(*s){
		case Symbole::POINT_VIR:
			a->pushSymbole(s);
			a->pushEtat(new Etat18());
			a->decaler();
			break;
		case Symbole::VIRGULE:
			a->pushSymbole(s);
			a->pushEtat(new Etat19());
			a->decaler();
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl; 
			break;
	}
}
