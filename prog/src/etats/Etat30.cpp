#include "Etat30.h"
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
void Etat30::transition(Automate* a, Symbole* s) //réduction règle 19
{
    Symbole* id = a->popSymbole();
    id->setType(Symbole::FACTEUR);
	a-> popState();
	a->etatCourant()->transition(a, id);
}
