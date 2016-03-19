#include "etats/Etat29.hpp"

#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat30.hpp"
#include "etats/Etat25.hpp"
#include "etats/Etat31.hpp"
#include "etats/Etat32.hpp"

#include <iostream>

Etat29::Etat29()
{
    //ctor
}

void Etat29::transition(Automate* a, Symbole* s)
{
    switch(*s){
		case Symbole::FACTEUR:
			a->pushSymbole(s);
			a->pushEtat(new Etat32());
			break;
		case Symbole::VALEUR:
			a->pushSymbole(s);
			a->pushEtat(new Etat31());
			a->decaler();
			break;
		case Symbole::IDENTIFIANT:
			a->pushSymbole(s);
			a->pushEtat(new Etat30());
			a->decaler();
			break;
		case Symbole::PARENTHESE_OUV:
			a->pushEtat(new Etat25());
			a->decaler();
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
	}
}
