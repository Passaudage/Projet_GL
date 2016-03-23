#include <iostream>
#include "etats/Etat25.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat30.hpp"
#include "etats/Etat31.hpp"
#include "etats/Etat26.hpp"
#include "etats/Etat24.hpp"
#include "etats/Etat28.hpp"

#include "Erreurs.hpp"

Etat25 Etat25::m_instance = Etat25();

Etat25::Etat25()
{
}

Etat25* Etat25::getInstance(){
	return &m_instance;
}


void Etat25::transition(Automate* a, Symbole* s)
{
#ifdef MAP
	std::cout << "Etat25" << std::endl;
#endif
     switch(*s){
		case Symbole::PARENTHESE_OUV:
			//~ a->pushEtat(new Etat25());
			a->pushEtat(Etat25::getInstance());
			a->decaler();
			break;
        case Symbole::IDENTIFIANT:
			a->pushSymbole(s);
			//~ a->pushEtat(new Etat30());
			a->pushEtat(Etat30::getInstance());
			a->decaler();
			break;
        case Symbole::VALEUR:
			a->pushSymbole(s);
			//~ a->pushEtat(new Etat31());
			a->pushEtat(Etat31::getInstance());
			a->decaler();
			break;
        case Symbole::EXPRESSION:
			//~ a->pushEtat(new Etat26());
			a->pushEtat(Etat26::getInstance());
			break;
        case Symbole::FACTEUR:
			//~ a->pushEtat(new Etat24());
			a->pushEtat(Etat24::getInstance());
			break;
        case Symbole::TERME:
			//~ a->pushEtat(new Etat28());
			a->pushEtat(Etat28::getInstance());
			break;


		default:
			throw ExceptionSymbole(s, ExceptionSymbole::symbole_non_attendu);
			break;
	}
}
