#include "Etat25.h"
#include "Automate.hpp"
#include "Symbole.hpp"

Etat25::Etat25()
{
    //ctor
}

Etat25::~Etat25()
{
    //dtor
}
void Etat25::transition(Automate* a, Symbole* s)
{
     switch(*s){
		case PARENTHESE_OUV:
			a->pushSymbole(s);
			a->pushEtat(new Etat25());
			break;
        case IDENTIFIANT:
			a->pushSymbole(s);
			a->pushEtat(new Etat30());
			break;
        case VALEUR:
			a->pushSymbole(s);
			a->pushEtat(new Etat31());
			break;
        case EXPRESSION:
			a->pushSymbole(s);
			a->pushEtat(new Etat26());
			break;
        case FACTEUR:
			a->pushSymbole(s);
			a->pushEtat(new Etat24());
			break;
        case TERME:
			a->pushSymbole(s);
			a->pushEtat(new Etat28());
			break;


		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
}
