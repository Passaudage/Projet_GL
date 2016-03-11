#include  "Etat0.hpp"

Etat0::Etat0()
{

}

void Etat0::transition(Automate* a, Symbole* s)
{
	switch(*s){
		case SYMBOLE_D:
			a->pushSymbole(s);
			a->pushState(new Etat1());
			break;
		case default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< endline; 
			break;
	}
}