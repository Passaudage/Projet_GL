#include "Etat19.h"
#include "Automate.hpp"
#include "Symbole.hpp"

Etat19::Etat19()
{
    //ctor
}

Etat19::~Etat19()
{
    //dtor
}

void Etat19::transition(Automate* a, Symbole* s)
{
    a->popSymbole();
	Symbole* val = (Valeur*) a->popSymbole();
	a->popSymbole();
	Symbole* id = (Identifiant*) a->popSymbole();
	Symbole* idc = (IDC*) a->popSymbole();
	idc->ajouterConstante(id->get(), val->getValeur());
	a-> popState();
	a-> popState();
	a-> popState();
	a-> popState();
	a-> popState();
	a->etatCourrant()->transition(a, idc);
}
