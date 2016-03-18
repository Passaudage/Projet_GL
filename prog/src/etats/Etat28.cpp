#include "Etat28.h"
#include "Automate.hpp"
#include "Symbole.hpp"

Etat28::Etat28()
{
    //ctor
}

Etat28::~Etat28()
{
    //dtor
}
void Etat28::transition(Automate* a, Symbole* s)
{
    switch(*s){
		case OPERATEUR_MUL:
			a->pushSymbole(s);
			a->pushEtat(new Etat29());
			break;
		case Symbole::POINT_VIR:
		case Symbole::PARENTHESE_FER:
		case Symbole::POINT_VIR:
			Symbole* terme = (Expression*) a->popSymbole();
			terme->setSymbole(Symbole::EXPRESSION);
			a->popEtat();
			a->etatCourant()->transition(a, terme);
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
	}
}
