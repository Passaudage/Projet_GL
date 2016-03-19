#include <iostream>

#include "etats/Etat8.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat9.hpp"

Etat8::Etat8()
{

}

void Etat8::transition(Automate* a, Symbole* s)
{
#ifdef MAP
	std::cout << "Etat8" << std::endl;
#endif
	
	switch(*s){
		case Symbole::AFFECTATION:
			a->pushEtat(new Etat9());
			a->decaler();
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl; 
			break;
	}
}
