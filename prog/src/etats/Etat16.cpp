#include <iostream>

#include "etats/Etat16.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat33.hpp"

Etat16::Etat16()
{

}

Etat16::~Etat16()
{

}

void Etat16::transition(Automate* a, Symbole* s)
{
	switch(*s){
		case Symbole::IDENTIFIANT:
			a->pushSymbole(s);
			a->pushEtat(new Etat33());
			a->decaler();
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl; 
			break;
	}
}
