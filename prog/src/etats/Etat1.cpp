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
	std::cout << "Etat1" << std::endl;
	switch(*s){
		case Symbole::INSTRUCTIONS:
		//OK
			a->pushSymbole(s);
			a->pushEtat(new Etat2());
			break;
		case Symbole::INSTRUCTION:
		//OK
			a->pushSymbole(s);
			a->pushEtat(new Etat10());
			break;
		case Symbole::VARIABLE:
		//OK
			a->pushEtat(new Etat3());
			a->decaler();
			break;
		case Symbole::CONSTANTE:
		//OK
			a->pushEtat(new Etat4());
			a->decaler();
			break;
		case Symbole::IDENTIFIANT:
			a->pushSymbole(s);
			a->pushEtat(new Etat8());
			a->decaler();
			break;
		case Symbole::LECTURE:
		//OK
			a->pushEtat(new Etat5());
			a->decaler();
			break;
		case Symbole::AFFICHAGE:
		//OK
			a->pushEtat(new Etat7());
			a->decaler();
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl; 
			break;
	}
}