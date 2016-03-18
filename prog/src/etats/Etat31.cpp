#include <iostream>
#include "etats/Etat31.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"

Etat31::Etat31()
{
    //ctor
}

Etat31::~Etat31()
{
    //dtor
}
void Etat31::transition(Automate* a, Symbole* s) //réduction règle 20
{
    Symbole* val= a->popSymbole();
    val->setType(Symbole::FACTEUR);
	a-> popEtat();
	a->etatCourant()->transition(a, val);
}
