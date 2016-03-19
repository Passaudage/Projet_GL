#include <iostream>

#include "etats/Etat16bis.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat16ter.hpp"

Etat16bis::Etat16bis()
{
    //ctor
}

Etat16bis::~Etat16bis()
{
    //dtor
}
void Etat16bis::transition(Automate* a, Symbole* s)
{
     switch(*s){
		case Symbole::EGAL:
			a->pushEtat(new Etat16ter());
			a->decaler();
			break;

		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
	}
}
