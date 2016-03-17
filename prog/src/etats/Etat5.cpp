#include <iostream>

#include "etats/Etat5.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat6.hpp"

Etat5::Etat5()
{

}

Etat5::~Etat5()
{

}

void Etat5::transition(Automate* a, Symbole* s)
{
	switch(*s){
		case Symbole::IDENTIFIANT:
			a->pushSymbole(s);
			a->pushEtat(new Etat6());
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl; 
			break;
	}
}
