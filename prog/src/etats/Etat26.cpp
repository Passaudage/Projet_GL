#include "Etat26.h"
#include "Automate.hpp"
#include "Symbole.hpp"

Etat26::Etat26()
{
    //ctor
}

Etat26::~Etat26()
{
    //dtor
}
void Etat26::transition(Automate* a, Symbole* s)
{
     switch(*s){
		case PARENTHESE_FER:
			a->pushSymbole(s);
			a->pushEtat(new Etat27());
			break;
        case OPERATEUR_ADD:
			a->pushSymbole(s);
			a->pushEtat(new Etat22());
			break;

		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
}
