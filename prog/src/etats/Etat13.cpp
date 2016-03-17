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
	switch(*s){
		case Symbole::POINT_VIR:
			a->pushSymbole(s);
			a->pushEtat(new Etat14());
			break;
		case Symbole::VIRGULE:
			a->pushSymbole(s);
			a->pushEtat(new Etat15());
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl; 
			break;
	}
}
