#include  "etats/Etat0.hpp"

#include <iostream>

#include "Automate.hpp"
#include "Symbole.hpp"
#include "Etat1.hpp"
#include "symboles/Declarations.hpp"

Etat0::Etat0()
{

}

Etat0::~Etat0()
{

}

void Etat0::transition(Automate* a, Symbole* s)
{
	switch(*s){
		case Symbole::DECLARATIONS:
			a->pushSymbole(s);
			a->pushEtat(new Etat1()); 
			break;
		case Symbole::VARIABLE:
			Symbole* declarations = new Declarations();			
			a->etatCourant()->transition(a, declarations);
			break;
		case Symbole::CONSTANTE:
			Symbole* declarations = new Declarations();			
			a->etatCourant()->transition(a, declarations);
			break;
		case Symbole::LECTURE:
			Symbole* declarations = new Declarations();			
			a->etatCourant()->transition(a, declarations);
			break;
		case Symbole::ECRITURE:
			Symbole* declarations = new Declarations();			
			a->etatCourant()->transition(a, declarations);
			break;
		default:
			std::cerr << "erreur, lecture non conforme à la grammaire" << std::endl; 
			break;
	}
}
