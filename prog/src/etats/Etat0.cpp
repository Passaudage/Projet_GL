#include "etats/Etat0.hpp"

#include <iostream>

#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat1.hpp"
#include "symboles/Declarations.hpp"

Etat0::Etat0()
{

}


void Etat0::transition(Automate* a, Symbole* s)
{
	switch(*s){
		case Symbole::DECLARATIONS:
			a->pushSymbole(s);
			a->pushEtat(new Etat1()); 
			a->decaler();
			break;
		case Symbole::VARIABLE:
		case Symbole::CONSTANTE:
		case Symbole::LECTURE:
		case Symbole::AFFICHAGE:
			{
				Symbole* declarations = new Declarations();			
				a->etatCourant()->transition(a, declarations);
				break;
			}
		default:
			std::cerr << "erreur, lecture non conforme à la grammaire" << std::endl; 
			break;
	}
}
