#include "Etat18.h"
#include "Automate.hpp"
#include "Symbole.hpp"

Etat18::Etat18()
{
    //ctor
}

Etat18::~Etat18()
{
    //dtor
}
void Etat18::transition(Automate* a, Symbole* s) //réduction de la règle 7
{
	a->popSymbole();
    Symbole* val = (Valeur) a->popSymbole();
    a->popSymbole();
    Symbole* id = (Identifiant*) a->popSymbole();
	Symbole* idc = (IDC*) a->popSymbole();
	a->popSymbole();
	Symbole* d = (Declarations*) a->popSymbole();
	d->ajouterConstante(id->get(), val->getValeur());
	d->enregistrerConstante(idc);
	d->
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a->etatCourant()->transition(a, d);
}
