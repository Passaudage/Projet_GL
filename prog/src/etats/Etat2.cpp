#include <iostream>
#include "etats/Etat2.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat10.hpp"
#include "etats/Etat8.hpp"
#include "etats/Etat5.hpp"
#include "etats/Etat7.hpp"

Etat2::Etat2()
{

}

Etat2::~Etat2()
{

}

void Etat2::transition(Automate* a, Symbole* s)
{
	switch(*s){
		case INSTRUCTION:
			a->pushSymbole(s);
			a->pushEtat(new Etat10());
			break;
		case IDENTIFIANT:
			a->pushSymbole(s);
			a->pushEtat(new Etat8());
			break;
		case LECTURE:
			a->pushSymbole(s);
			a->pushEtat(new Etat5());
			break;
		case AFFICHAGE:
			a->pushSymbole(s);
			a->pushEtat(new Etat7());
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl; 
		break;
	}
}