#include <iostream>

#include "etats/Etat16bis.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat16ter.hpp"

Etat16bis Etat16bis::m_instance = Etat16bis();

Etat16bis::Etat16bis()
{
}

Etat16bis* Etat16bis::getInstance(){
	return &m_instance;
}


void Etat16bis::transition(Automate* a, Symbole* s)
{
#ifdef MAP
	std::cout << "Etat16bis" << std::endl;
#endif
     switch(*s){
		case Symbole::EGAL:
			//~ a->pushEtat(new Etat16ter());
			a->pushEtat(Etat16ter::getInstance());
			a->decaler();
			break;

		default:
			a->throwLexerError("Symbole non attendu par la grammaire");
			break;
	}
}
