#include <iostream>

#include "etats/Etat9.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat25.hpp"
#include "etats/Etat30.hpp"
#include "etats/Etat31.hpp"
#include "etats/Etat24.hpp"
#include "etats/Etat28.hpp"
#include "etats/Etat21.hpp"

Etat9::Etat9()
{

}

Etat9::~Etat9()
{

}

void Etat9::transition(Automate* a, Symbole* s)
{
	switch(*s){
		case Symbole::TERME:
			a->pushSymbole(s);
			a->pushEtat(new Etat28());
			break;
		case Symbole::FACTEUR:
			a->pushSymbole(s);
			a->pushEtat(new Etat24());
			break;
		case Symbole::EXPRESSION:
			a->pushSymbole(s);
			a->pushEtat(new Etat21());
			break;
		case Symbole::VALEUR:
			a->pushSymbole(s);
			a->pushEtat(new Etat31());
			break;
		case Symbole::IDENTIFIANT:
			a->pushSymbole(s);
			a->pushEtat(new Etat30());
			break;
		case Symbole::PARENTHESE_OUV:
			a->pushSymbole(s);
			a->pushEtat(new Etat25());
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl; 
			break;
	}
}
