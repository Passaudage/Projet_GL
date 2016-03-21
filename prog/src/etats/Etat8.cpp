#include <iostream>

#include "etats/Etat8.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat9.hpp"

Etat8 Etat8::m_instance = Etat8();

Etat8::Etat8()
{
}

Etat8* Etat8::getInstance(){
	return &m_instance;
}

void Etat8::transition(Automate* a, Symbole* s)
{
#ifdef MAP
	std::cout << "Etat8" << std::endl;
#endif
	
	switch(*s){
		case Symbole::AFFECTATION:
			//~ a->pushEtat(new Etat9());
			a->pushEtat(Etat9::getInstance());
			a->decaler();
			break;
		default:
			a->throwLexerError("Symbole non attendu par la grammaire");
			break;
	}
}
