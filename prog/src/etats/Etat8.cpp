#include <iostream>

#include "etats/Etat8.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat9.hpp"

Etat8::Etat8()
{

}

Etat8::~Etat8()
{

}

void Etat8::transition(Automate* a, Symbole* s)
{
	switch(*s){
		case Symbole::AFFECTATION:
			a->pushSymbole(s);
			a->pushEtat(new Etat9());
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl; 
			break;
	}
}
