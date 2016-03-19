#include <iostream>
#include "etats/Etat30.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"

Etat30::Etat30()
{
    //ctor
}

Etat30::~Etat30()
{
    //dtor
}
void Etat30::transition(Automate* a, Symbole* ) //réduction règle 19
{
    Symbole* id = a->popSymbole();
    id->setType(Symbole::FACTEUR);
	a-> popEtat();
	a->etatCourant()->transition(a, id);
}
