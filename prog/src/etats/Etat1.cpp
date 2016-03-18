#include <iostream>

#include "etats/Etat1.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat2.hpp"
#include "etats/Etat10.hpp"
#include "etats/Etat3.hpp"
#include "etats/Etat4.hpp"
#include "etats/Etat8.hpp"
#include "etats/Etat5.hpp"
#include "etats/Etat7.hpp"

Etat1::Etat1()
{

}

Etat1::~Etat1()
{

}

void Etat1::transition(Automate* a, Symbole* s)
{
	switch(*s){
		case Symbole::INSTRUCTIONS:
			a->pushSymbole(s);
			a->pushEtat(new Etat2());
			//a->decaler();
			break;
		case Symbole::INSTRUCTION:
			a->pushSymbole(s);
			a->pushEtat(new Etat10());
			a->decaler();
			break;
		case Symbole::VARIABLE:
			a->pushSymbole(s);
			a->pushEtat(new Etat3());
			a->decaler();
			break;
		case Symbole::CONSTANTE:
			a->pushSymbole(s);
			a->pushEtat(new Etat4());
			a->decaler();
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