#include <iostream>

#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat3.hpp"
#include "etats/Etat12.hpp"
#include "symboles/Declarations.hpp"

Etat3::Etat3()
{

}

Etat3::~Etat3()
{

}

void Etat3::transition(Automate* a, Symbole* s)
{
	switch(*s){
		case Symbole::DECLARATION_VAR:
			a->pushSymbole(s);
			a->pushEtat(new Etat12());
			break;
		case Symbole::IDENTIFIANT:
			Symbole* idv = new IDV();
			a->etatCourant()->transition(a, idv);
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl; 
		break;
	}
}