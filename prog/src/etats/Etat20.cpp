	#include "Etat20.h"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/Affichage.hpp"

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
		case OPERATEUR_ADD:
			a->pushSymbole(s);
			a->pushEtat(new Etat22());
			break;
		case Symbole::LECTURE:
		case Symbole::ECRITURE:
		case Symbole::AFFECTATION:
			Symbole* expr = (Expression*) a->popSymbole();
			a->popSymbole();
			Symbole* ecriture = new Affichage(*expr);
			a->popEtat();
			a->popEtat();
			Sa->etatCourant()->transition(a, lecture);
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
}
