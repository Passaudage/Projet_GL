#include <iostream>
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat22.hpp"
#include "etats/Etat23.hpp"
#include "etats/Etat24.hpp"
#include "etats/Etat25.hpp"
#include "etats/Etat30.hpp"
#include "etats/Etat31.hpp"

Etat22 Etat22::m_instance = Etat22();

Etat22::Etat22()
{
}

Etat22* Etat22::getInstance(){
	return &m_instance;
}


void Etat22::transition(Automate* a, Symbole* s)
{
#ifdef MAP
	std::cout << "Etat22" << std::endl;
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
        case Symbole::FACTEUR:
			//~ a->pushEtat(new Etat24());
			a->pushEtat(Etat24::getInstance());
			break;
        case Symbole::TERME:
			//~ a->pushEtat(new Etat23());
			a->pushEtat(Etat23::getInstance());
			break;
		default:
			std::cerr<<"erreur, lecture non conforme � la grammaire"<<
				std::endl;
			break;
		}
}
