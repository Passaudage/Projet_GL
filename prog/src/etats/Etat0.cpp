#include "etats/Etat0.hpp"

#include <iostream>

#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat1.hpp"
#include "symboles/Declarations.hpp"

#include "Erreurs.hpp"

Etat0 Etat0::m_instance;

Etat0::Etat0()
{
}

Etat0* Etat0::getInstance(){
	return &m_instance;
}

void Etat0::transition(Automate* a, Symbole* s)
{
#ifdef MAP
	std::cout << "Etat0" << std::endl;
#endif
	switch(*s){
		case Symbole::DECLARATIONS:
			//~ a->pushEtat(new Etat1()); 
			a->pushEtat(Etat1::getInstance()); 
			break;
		case Symbole::IDENTIFIANT:
		case Symbole::VARIABLE:
		case Symbole::CONSTANTE:
		case Symbole::LECTURE:
		case Symbole::AFFICHAGE:
			{
				Symbole* declarations = new Declarations();			
				a->pushSymbole(declarations);
				a->etatCourant()->transition(a, declarations);
				break;
			}
		default:
			throw ExceptionSymbole(s, ExceptionSymbole::symbole_non_attendu);
			break;
	}
}
