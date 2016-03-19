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
#ifdef MAP
	std::cout << "Etat10" << std::endl;
#endif
	switch(*s){
		case Symbole::POINT_VIR:
			//a->pushSymbole(s);
			a->pushEtat(new Etat11());
			a->decaler();
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl; 
			break;
	}
}
