#include <iostream>

#include "etats/Etat12.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat13.hpp"

Etat12::Etat12()
{

}

Etat12::~Etat12()
{

}

void Etat12::transition(Automate* a, Symbole* s)
{
	switch(*s){
		case Symbole::IDENTIFIANT:
			a->pushSymbole(s);
			a->pushEtat(new Etat13());
			a->decaler();
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl; 
			break;
	}
}
