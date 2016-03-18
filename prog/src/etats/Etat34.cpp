#include <iostream>
#include "etats/Etat34.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat17.hpp"

Etat34::Etat34()
{
    //ctor
}

Etat34::~Etat34()
{
    //dtor
}
void Etat34::transition(Automate* a, Symbole* s)
{
     switch(*s){
		case Symbole::VALEUR:
			a->pushSymbole(s);
			a->pushEtat(new Etat17());
			a->decaler();
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
	}
}
