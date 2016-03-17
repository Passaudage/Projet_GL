#include <iostream>

#include "etats/Etat6.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "Lecture.hpp"

Etat6::Etat6()
{

}

Etat6::~Etat6()
{

}

void Etat6::transition(Automate* a, Symbole* s) //réduction de la règle 11
{
	Symbole* id = a->popSymbole();
	Symbole* lire = a->popSymbole();
	Symbole* lecture = new Lecture(lire, id);
	a-> popState();
	a-> popState();
	a->etatCourrant()->transition(a, lecture);
}