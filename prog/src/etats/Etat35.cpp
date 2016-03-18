#include <iostream>

#include "etats/Etat35.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat36.hpp"

Etat35::Etat35()
{
    //ctor
}

Etat35::~Etat35()
{
    //dtor
}
void Etat35::transition(Automate* a, Symbole* s)
{
    switch(*s){
		case Symbole::POINT_VIR:
			a->pushSymbole(s);
			a->pushEtat(new Etat36());
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
	}
}
