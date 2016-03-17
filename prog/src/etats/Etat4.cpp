#include <iostream>

#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat4.hpp"
#include "etats/Etat16.hpp"

Etat4::Etat4()
{

}

Etat4::~Etat4()
{

}

void Etat4::transition(Automate* a, Symbole* s)
{
	switch(*s){
		case DECLARATION_CON:
			a->pushSymbole(s);
			a->pushEtat(new Etat16());
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl; 
		break;
	}
}