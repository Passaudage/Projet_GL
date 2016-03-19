#include <iostream>
#include "etats/Etat19.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/Declarations.hpp"
#include "symboles/Valeur.hpp"
#include "symboles/Identifiant.hpp"

Etat19::Etat19()
{
    //ctor
}

Etat19::~Etat19()
{
    //dtor
}

void Etat19::transition(Automate* a, Symbole* )
{
#ifdef MAP
	std::cout << "Etat19" << std::endl;
#endif
	Valeur* val = dynamic_cast<Valeur*> (a->popSymbole());
	Identifiant* id = dynamic_cast<Identifiant*> (a->popSymbole());
	Declarations::IDC* idc = dynamic_cast<Declarations::IDC*> (a->popSymbole());
	
	idc->ajouterConstante(id->get(), val->getValeur());

	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	
	a->etatCourant()->transition(a, idc);
}
