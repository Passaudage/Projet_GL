#include <iostream>
#include "etats/Etat28.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat29.hpp"
#include "symboles/Expression.hpp"

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
		case Symbole::OPERATEUR_MUL:
			a->pushSymbole(s);
			a->pushEtat(new Etat29());
			break;
		case Symbole::POINT_VIR:
		case Symbole::PARENTHESE_FER:
		case Symbole::OPERATEUR_ADD:
			{
				Expression* terme = (Expression*) a->popSymbole();
				terme->setType(Symbole::EXPRESSION);
				a->popEtat();
				a->etatCourant()->transition(a, terme);
				break;
			}
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
	}
}
