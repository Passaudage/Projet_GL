#include <iostream>

#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat4.hpp"
#include "etats/Etat16.hpp"
#include "symboles/Declarations.hpp"

Etat4::Etat4()
{

}

Etat4::~Etat4()
{

}

void Etat4::transition(Automate* a, Symbole* s)
{
	switch(*s){
		case Symbole::DECLARATION_CON:
			a->pushSymbole(s);
			a->pushEtat(new Etat16());
			a->decaler();
			break;
		case Symbole::IDENTIFIANT:
			{
				Symbole* idc = new Declarations::IDC();
				a->etatCourant()->transition(a, idc);
			}
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl; 
		break;
	}
}
