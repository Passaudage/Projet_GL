#include "Etat21.h"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/Afectation.hpp"

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
		case OPERATEUR_ADD:
			a->pushSymbole(s);
			a->pushEtat(new Etat22());
			break;
		case Symbole::LECTURE:
		case Symbole::ECRITURE:
		case Symbole::AFFECTATION:
			Symbole* expr = (Expression*) a->popSymbole();
			a->popSymbole();
			Symbole* id = (Identifiant*) a->popSymbole();
			Symbole* affect = new Affectation(*expr, *id);
			a->popEtat();
			a->popEtat();
			a->popEtat();
			a->etatCourant()->transition(a, affect);
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
}
