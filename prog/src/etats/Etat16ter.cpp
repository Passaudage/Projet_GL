#include <iostream>
#include "etats/Etat16ter.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat17.hpp"

Etat16ter::Etat16ter()
{
    //ctor
}

Etat16ter::~Etat16ter()
{
    //dtor
}
void Etat16ter::transition(Automate* a, Symbole* s)
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
