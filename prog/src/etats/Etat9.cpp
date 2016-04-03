#include <iostream>

#include "etats/Etat9.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat25.hpp"
#include "etats/Etat30.hpp"
#include "etats/Etat31.hpp"
#include "etats/Etat24.hpp"
#include "etats/Etat28.hpp"
#include "etats/Etat21.hpp"

#include "Erreurs.hpp"

Etat9 Etat9::m_instance;

Etat9::Etat9()
{
}

Etat9* Etat9::getInstance(){
	return &m_instance;
}

void Etat9::transition(Automate* a, Symbole* s)
{
#ifdef MAP
	std::cout << "Etat9" << std::endl;
#endif
	switch (*s) {
		case Symbole::TERME:
			//~ a->pushEtat(new Etat28());
			a->pushEtat(Etat28::getInstance());
			break;
		case Symbole::FACTEUR:
			//~ a->pushEtat(new Etat24());
			a->pushEtat(Etat24::getInstance());
			break;
		case Symbole::EXPRESSION:
			//~ a->pushEtat(new Etat21());
			a->pushEtat(Etat21::getInstance());
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
