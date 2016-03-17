#include "Etat23.h"
#include "Automate.hpp"
#include "Symbole.hpp"

Etat23::Etat23()
{
    //ctor
}

Etat23::~Etat23()
{
    //dtor
}
void Etat23::transition(Automate* a, Symbole* s)
{
    switch(*s){
		case OPERATEUR_MUL:
			a->pushSymbole(s);
			a->pushEtat(new Etat29());
			break;

		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
}
