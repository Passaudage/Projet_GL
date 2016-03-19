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
	// 
    Valeur* val = dynamic_cast<Valeur*> (a->popSymbole());
    Identifiant* id = dynamic_cast<Identifiant*> (a->popSymbole());
	Declarations::IDC* idc = dynamic_cast<Declarations::IDC*> (a->popSymbole());
	Declarations* d = dynamic_cast<Declarations*> (a->popSymbole());

	std::cout << "VALEUR : " << val->getValeur() << std::endl;;

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
