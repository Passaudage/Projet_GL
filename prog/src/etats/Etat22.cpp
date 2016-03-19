#include <iostream>
#include "etats/Etat22.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat25.hpp"
#include "etats/Etat30.hpp"
#include "etats/Etat31.hpp"
#include "etats/Etat24.hpp"
#include "etats/Etat28.hpp"

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
		case Symbole::PARENTHESE_OUV:
			a->pushSymbole(s);
			a->pushEtat(new Etat25());
			a->decaler();
			break;
        case Symbole::IDENTIFIANT:
			a->pushSymbole(s);
			a->pushEtat(new Etat30());
			a->decaler();
			break;
        case Symbole::VALEUR:
			a->pushSymbole(s);
			a->pushEtat(new Etat31());
			a->decaler();
			break;
        case Symbole::FACTEUR:
			a->pushSymbole(s);
			a->pushEtat(new Etat24());
			break;
        case Symbole::TERME:
			a->pushSymbole(s);
			a->pushEtat(new Etat28());
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
		}
}
