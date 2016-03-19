#include <iostream>

#include "etats/Etat7.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat25.hpp"
#include "etats/Etat30.hpp"
#include "etats/Etat31.hpp"
#include "etats/Etat24.hpp"
#include "etats/Etat28.hpp"
#include "etats/Etat20.hpp"
#include "etats/Etat32.hpp"

Etat7::Etat7()
{

}

Etat7::~Etat7()
{

}

void Etat7::transition(Automate* a, Symbole* s)
{
	std::cout << "Etat7" << std::endl;
	switch(*s){
		case Symbole::TERME:
			a->pushSymbole(s);
			a->pushEtat(new Etat28());
			break;
		case Symbole::FACTEUR:
			a->pushEtat(new Etat24());
			a->etatCourant()->transition(a, s);
			break;
		case Symbole::EXPRESSION:
			a->pushSymbole(s);
			a->pushEtat(new Etat20());
			break;
		case Symbole::VALEUR:
			a->pushSymbole(s);
			a->pushEtat(new Etat32());
			a->decaler();
			break;
		case Symbole::IDENTIFIANT:
			a->pushSymbole(s);
			a->pushEtat(new Etat31());
			a->decaler();
			break;
		case Symbole::PARENTHESE_OUV:
			a->pushSymbole(s);
			a->pushEtat(new Etat25());
			a->decaler();
			break;
		default:
			throw "Etat7, lecture non conforme à la grammaire";
			break;
	}
}
