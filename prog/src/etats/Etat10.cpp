#include <iostream>

#include "etats/Etat10.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat11.hpp"

Etat10::Etat10()
{

}

Etat10::~Etat10()
{

}

void Etat10::transition(Automate* a, Symbole* s)
{
	switch(*s){
		case Symbole::INSTRUCTIONS:
			a->pushSymbole(s);
			a->pushEtat(new Etat11());
			a->decaler();
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl; 
			break;
	}
}
