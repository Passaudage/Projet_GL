#include <iostream>
#include "etats/Etat26.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat27.hpp"
#include "etats/Etat22.hpp"

#include "Erreurs.hpp"

Etat26 Etat26::m_instance = Etat26();

Etat26::Etat26()
{
}

Etat26* Etat26::getInstance(){
	return &m_instance;
}


void Etat26::transition(Automate* a, Symbole* s)
{
#ifdef MAP
	std::cout << "Etat26" << std::endl;
#endif
     switch(*s){
		case Symbole::PARENTHESE_FER:
			//~ a->pushEtat(new Etat27());
			a->pushEtat(Etat27::getInstance());
			a->decaler();
			break;
        case Symbole::OPERATEUR_ADD:
			a->pushSymbole(s);
			//~ a->pushEtat(new Etat22());
			a->pushEtat(Etat22::getInstance());
			a->decaler();
			break;
		default:
			throw ExceptionSymbole(s, ExceptionSymbole::symbole_non_attendu);
			break;
		}
}
