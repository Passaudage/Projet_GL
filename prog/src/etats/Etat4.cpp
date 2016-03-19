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
#ifdef MAP
	std::cout << "Etat4" << std::endl;
#endif
	// Tout OK
	switch(*s){
		case Symbole::DECLARATION_CON:
		// OK
			a->pushSymbole(s);
			a->pushEtat(new Etat16());
			break;
		case Symbole::IDENTIFIANT:
		// OK
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
