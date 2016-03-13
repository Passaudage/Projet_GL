#include  "etats/Etat0.hpp"

#include <iostream>

#include "Automate.hpp"
#include "Symbole.hpp"

Etat0::Etat0()
{

}

Etat0::~Etat0()
{

}

void Etat0::transition(Automate* a, Symbole* s)
{
	switch(*s){
		case Symbole::DECLARATIONS:
			a->pushSymbole(s);
			/* a->pushEtat(new Etat1()); */
			break;
		default:
			std::cerr << "erreur, lecture non conforme à la grammaire" << std::endl; 
			break;
	}
}
