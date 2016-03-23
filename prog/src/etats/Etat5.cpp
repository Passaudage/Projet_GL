#include <iostream>

#include "etats/Etat5.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat6.hpp"

#include "Erreurs.hpp"

Etat5 Etat5::m_instance = Etat5();

Etat5::Etat5()
{
}

Etat5* Etat5::getInstance(){
	return &m_instance;
}

void Etat5::transition(Automate* a, Symbole* s)
{
#ifdef MAP
	std::cout << "Etat5" << std::endl;
#endif

	switch(*s){
		case Symbole::IDENTIFIANT:
			a->pushSymbole(s);
			//~ a->pushEtat(new Etat6());
			a->pushEtat(Etat6::getInstance());
			a->decaler();
			break;
		default:
			throw ExceptionSymbole(s, ExceptionSymbole::symbole_non_attendu);
			break;
	}
}
