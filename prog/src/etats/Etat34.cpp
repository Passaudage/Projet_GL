#include "Etat34.h"
#include "Automate.hpp"
#include "Symbole.hpp"

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
		case VALEUR:
			a->pushSymbole(s);
			a->pushEtat(new Etat17());
			break;


		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
	}
}
