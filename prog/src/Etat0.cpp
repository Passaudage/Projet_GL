#include  "Etat0.hpp"

Etat0::Etat0()
{

}

Etat0::~Etat0()
{

}

void Etat0::transition(Automate* a, Symbole* s)
{
	switch(*s){
		case DECLARATIONS:
			a->pushSymbole(s);
			a->pushEtat(new Etat1());
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl; 
			break;
	}
}