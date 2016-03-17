#include <iostream>

#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat3.hpp"
#include "etats/Etat12.hpp"

Etat3::Etat3()
{

}

Etat3::~Etat3()
{

}

void Etat3::transition(Automate* a, Symbole* s)
{
	switch(*s){
		case DECLARATION_VAR:
			a->pushSymbole(s);
			a->pushEtat(new Etat12());
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl; 
		break;
	}
}