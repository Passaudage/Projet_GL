#include "Etat21.h"
#include "Automate.hpp"
#include "Symbole.hpp"

Etat21::Etat21()
{
    //ctor
}

Etat21::~Etat21()
{
    //dtor
}
void Etat21::transition(Automate* a, Symbole* s)
{
    switch(*s){
		case OPERATEUR_ADD:
			a->pushSymbole(s);
			a->pushEtat(new Etat22());
			break;

		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
}
