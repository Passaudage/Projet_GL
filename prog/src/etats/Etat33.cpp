#include <iostream>

#include "etats/Etat33.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat34.hpp"

Etat33::Etat33()
{
    //ctor
}

Etat33::~Etat33()
{
    //dtor
}
void Etat33::transition(Automate* a, Symbole* s)
{
     switch(*s){
		case Symbole::EGAL:
			a->pushSymbole(s);
			a->pushEtat(new Etat34());
			break;

		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
	}
}
