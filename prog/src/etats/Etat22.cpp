#include "Etat22.h"
#include "Automate.hpp"
#include "Symbole.hpp"
Etat22::Etat22()
{
    //ctor
}

Etat22::~Etat22()
{
    //dtor
}
void Etat22::transition(Automate* a, Symbole* s)
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

        case FACTEUR:
			a->pushSymbole(s);
			a->pushEtat(new Etat24());
			break;
        case TERME:
			a->pushSymbole(s);
			a->pushEtat(new Etat28());
			break;


		default:
			std::cerr<<"erreur, lecture non conforme � la grammaire"<< std::endl;
			break;
}
