#include  "Etat0.hpp"

#include "Symbole.hpp"

Etat0::Etat0()
{

}

Etat0::~Etat0()
{

}

void Etat0::transition(Automate* a, Symbole* s)
{
	switch(*s){
		case SYMBOLE_D:
			a->pushSymbole(s);
			a->pushEtat(new Etat0());
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl; 
			break;
	}
}