#include "Etat20.h"
#include "Automate.hpp"
#include "Symbole.hpp"

Etat20::Etat20()
{
    //ctor
}

Etat20::~Etat20()
{
    //dtor
}
void Etat20::transition(Automate* a, Symbole* s)
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
