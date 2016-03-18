#include <iostream>
#include "etats/Etat2.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat35.hpp"
#include "etats/Etat8.hpp"
#include "etats/Etat5.hpp"
#include "etats/Etat7.hpp"

Etat2::Etat2()
{

}

Etat2::~Etat2()
{

}

void Etat2::transition(Automate* a, Symbole* s)
{
	switch(*s){
		case Symbole::INSTRUCTION:
			a->pushSymbole(s);
			a->pushEtat(new Etat35());
			break;
		case Symbole::IDENTIFIANT:
			a->pushSymbole(s);
			a->pushEtat(new Etat8());
			a->decaler();
			break;
		case Symbole::LECTURE:
			a->pushSymbole(s);
			a->pushEtat(new Etat5());
			a->decaler();
			break;
		case Symbole::AFFICHAGE:
			a->pushSymbole(s);
			a->pushEtat(new Etat7());
			a->decaler();
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl; 
		break;
	}
}
