#include "Etat29.h"
#include "Automate.hpp"
#include "Symbole.hpp"

Etat29::Etat29()
{
    //ctor
}

Etat29::~Etat29()
{
    //dtor
}
void Etat29::transition(Automate* a, Symbole* s)
{
    switch(*s){
		case FACTEUR:
			a->pushSymbole(s);
			a->pushEtat(new Etat32());
			break;
		case VALEUR:
			a->pushSymbole(s);
			a->pushEtat(new Etat31());
			break;
		case IDENTIFIANT:
			a->pushSymbole(s);
			a->pushEtat(new Etat30());
			break;

		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
	}
}
