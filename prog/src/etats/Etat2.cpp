#include <iostream>
#include "etats/Etat2.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat35.hpp"
#include "etats/Etat8.hpp"
#include "etats/Etat5.hpp"
#include "etats/Etat7.hpp"

#include "symboles/Instructions.hpp"
#include "symboles/Declarations.hpp"
#include "symboles/Programme.hpp"

#include "Erreurs.hpp"

Etat2 Etat2::m_instance;

Etat2::Etat2()
{
}

Etat2* Etat2::getInstance(){
	return &m_instance;
}

void Etat2::transition(Automate* a, Symbole* s)
{
#ifdef MAP
	std::cout << "Etat2" << std::endl;
#endif
	switch(*s){
		case Symbole::INSTRUCTION:
			//~ a->pushEtat(new Etat35());
			a->pushEtat(Etat35::getInstance());
			break;
		case Symbole::IDENTIFIANT:
			a->pushSymbole(s);
			//~ a->pushEtat(new Etat8());
			a->pushEtat(Etat8::getInstance());
			a->decaler();
			break;
		case Symbole::LECTURE:
			//~ a->pushEtat(new Etat5());
			a->pushEtat(Etat5::getInstance());
			a->decaler();
			break;
		case Symbole::AFFICHAGE:
			//~ a->pushEtat(new Etat7());
			a->pushEtat(Etat7::getInstance());
			a->decaler();
			break;
		case Symbole::FINDEFLUX:
			{
				// on récupère Instructions
				Instructions* instructions =
					dynamic_cast<Instructions*> (a->popSymbole());

				// puis Declarations
				Declarations* declarations =
					dynamic_cast<Declarations*> (a->popSymbole());

				// on créé Programme
				Symbole* programme =
					(Symbole*) new Programme(declarations, instructions);

				a->pushSymbole(programme);
				a->popEtat();
				a->popEtat();
				a->popEtat();

#ifdef MAP
				std::cout << "FIN DE FLUX !!" << std::endl;
#endif
			}
			break;
		default:
			throw ExceptionSymbole(s, ExceptionSymbole::symbole_non_attendu);
		break;
	}
}
