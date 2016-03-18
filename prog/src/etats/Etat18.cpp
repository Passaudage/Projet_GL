#include <iostream>
#include "etats/Etat18.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/Declarations.hpp"
#include "symboles/Identifiant.hpp"
#include "symboles/Valeur.hpp"

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
    Valeur* val = (Valeur*) a->popSymbole();
    a->popSymbole();
    Identifiant* id = (Identifiant*) a->popSymbole();
	Declarations::IDC* idc = (Declarations::IDC*) a->popSymbole();
	a->popSymbole();
	Declarations* d = (Declarations*) a->popSymbole();
	idc->ajouterConstante(id->get(), val->getValeur());
	d->enregistrerConstantes(*idc);
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a->etatCourant()->transition(a, d);
}
