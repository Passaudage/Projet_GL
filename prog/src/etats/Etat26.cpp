#include <iostream>
#include "etats/Etat26.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat27.hpp"
#include "etats/Etat22.hpp"

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
		case Symbole::PARENTHESE_FER:
        case Symbole::OPERATEUR_ADD:
			a->pushSymbole(s);
			a->pushEtat(new Etat22());
			break;
		default:
			std::cerr<<"erreur, lecture non conforme � la grammaire"<< std::endl;
			break;
		}
}
