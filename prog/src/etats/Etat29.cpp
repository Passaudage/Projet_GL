#include "etats/Etat29.hpp"

#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat30.hpp"
#include "etats/Etat25.hpp"
#include "etats/Etat31.hpp"
#include "etats/Etat32.hpp"

#include "Erreurs.hpp"

#include <iostream>

Etat29 Etat29::m_instance;

Etat29::Etat29()
{
}

Etat29* Etat29::getInstance(){
	return &m_instance;
}


void Etat29::transition(Automate* a, Symbole* s)
{
#ifdef MAP
	std::cout << "Etat29" << std::endl;
#endif
    switch(*s){
		case Symbole::FACTEUR:
			//~ a->pushEtat(new Etat32());
			a->pushEtat(Etat32::getInstance());
			break;
		case Symbole::VALEUR:
			a->pushSymbole(s);
			//~ a->pushEtat(new Etat31());
			a->pushEtat(Etat31::getInstance());
			a->decaler();
			break;
		case Symbole::IDENTIFIANT:
			a->pushSymbole(s);
			//~ a->pushEtat(new Etat30());
			a->pushEtat(Etat30::getInstance());
			a->decaler();
			break;
		case Symbole::PARENTHESE_OUV:
			//~ a->pushEtat(new Etat25());
			a->pushEtat(Etat25::getInstance());
			a->decaler();
			break;
		default:
			throw ExceptionSymbole(s, ExceptionSymbole::symbole_non_attendu);
			break;
	}
}
