#include <iostream>
#include "etats/Etat21.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat22.hpp"
#include "symboles/Affectation.hpp"

Etat21::Etat21()
{
    //ctor
}

Etat21::~Etat21()
{
    //dtor
}
void Etat21::transition(Automate* a, Symbole* s)
{
    switch(*s){
		case Symbole::OPERATEUR_ADD:
			a->pushSymbole(s);
			a->pushEtat(new Etat22());
			a->decaler();
			break;
		case Symbole::POINT_VIR:
			{
				Expression* expr = (Expression*) a->popSymbole();
				a->popSymbole();
				Identifiant* id = (Identifiant*) a->popSymbole();
				Symbole* affect = new Affectation(*expr, *id);
				a->popEtat();
				a->popEtat();
				a->popEtat();
				a->etatCourant()->transition(a, affect);
			}
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
		}
}
