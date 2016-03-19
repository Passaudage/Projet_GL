#include <iostream>
#include "etats/Etat28.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat29.hpp"
#include "symboles/Expression.hpp"

Etat28 Etat28::m_instance = Etat28();

Etat28::Etat28()
{
}

Etat28* Etat28::getInstance(){
	return &m_instance;
}


void Etat28::transition(Automate* a, Symbole* s)
{
#ifdef MAP
	std::cout << "Etat28" << std::endl;
#endif
    switch(*s){
		case Symbole::OPERATEUR_MUL:
			a->pushSymbole(s);
			//~ a->pushEtat(new Etat29());
			a->pushEtat(Etat29::getInstance());
			a->decaler();
			break;

		case Symbole::POINT_VIR:
		case Symbole::PARENTHESE_FER:
		case Symbole::OPERATEUR_ADD:
			{
				Symbole* symbole = a->symboleCourant();
				symbole->setType(Symbole::EXPRESSION);
				a->popEtat();
				a->etatCourant()->transition(a, symbole);
			}
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
	}
}
