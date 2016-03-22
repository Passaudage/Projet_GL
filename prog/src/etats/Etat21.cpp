#include <iostream>
#include "etats/Etat21.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat22.hpp"
#include "symboles/Affectation.hpp"
#include "symboles/Declarations.hpp"

Etat21 Etat21::m_instance = Etat21();

Etat21::Etat21()
{
}

Etat21* Etat21::getInstance(){
	return &m_instance;
}


void Etat21::transition(Automate* a, Symbole* s)
{
#ifdef MAP
	std::cout << "Etat21" << std::endl;
#endif

    switch(*s){
		case Symbole::OPERATEUR_ADD:
			a->pushSymbole(s);
			//~ a->pushEtat(new Etat22());
			a->pushEtat(Etat22::getInstance());
			a->decaler();
			break;
		case Symbole::POINT_VIR:
			{
#ifdef MAP
				std::cout << "Reduction de Instr -> id := expr" << std::endl;
#endif
				Expression* expr = (Expression*) a->popSymbole();
				Identifiant* id = (Identifiant*) a->popSymbole();
				Symbole* affect = new Affectation(*expr, *id);

				Declarations* declarations;

				if(int(*(a->symboleCourant())) == Symbole::Type::DECLARATIONS) {
					declarations = (dynamic_cast<Declarations*> (a->symboleCourant()));
				} else {
					Symbole* temp = a->popSymbole();
					declarations = (dynamic_cast<Declarations*> (a->symboleCourant()));
					a->pushSymbole(temp);
				}

				declarations->signerUtiliser(expr);
				declarations->signerAffecter(id);

				a->pushSymbole(affect);
				a->popEtat();
				a->popEtat();
				a->popEtat();
				a->etatCourant()->transition(a, affect);
			}
			break;
		default:
			throw "Erreur, lecture non conforme � la grammaire ! ";
			break;
		}
}
