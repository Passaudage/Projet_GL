#include <iostream>

#include "etats/Etat6.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/Lecture.hpp"

Etat6::Etat6()
{

}

Etat6::~Etat6()
{

}

void Etat6::transition(Automate* a, Symbole* s) //réduction de la règle 11
{
	Symbole* id = (Identifiant*) a->popSymbole();
	a->popSymbole;
	Symbole* lecture = new Lecture(*id);
	a-> popEtat();
	a-> popEtat();
	a->etatCourant()->transition(a, lecture);
}
