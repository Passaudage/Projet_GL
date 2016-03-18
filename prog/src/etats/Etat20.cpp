#include <iostream>
#include "etats/Etat20.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/Affichage.hpp"
#include "etats/Etat22.hpp"

Etat20::Etat20()
{
    //ctor
}

Etat20::~Etat20()
{
    //dtor
}
void Etat20::transition(Automate* a, Symbole* s)
{
    switch(*s){
		case Symbole::OPERATEUR_ADD:
			a->pushSymbole(s);
			a->pushEtat(new Etat22());
			break;
		case Symbole::LECTURE:
		case Symbole::AFFICHAGE:
		case Symbole::AFFECTATION:
			{
				Expression* expr = (Expression*) a->popSymbole();
				a->popSymbole();
				Symbole* ecriture = new Affichage(*expr);
				a->popEtat();
				a->popEtat();
				a->etatCourant()->transition(a, ecriture);
				break;
			}
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
	}
}
