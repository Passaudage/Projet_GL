#include <iostream>
#include "etats/Etat20.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/Affichage.hpp"
#include "etats/Etat22.hpp"

Etat20::Etat20()
{
    //ctor
}

void Etat20::transition(Automate* a, Symbole* s)
{
#ifdef MAP
	std::cout << "Etat20" << std::endl;
#endif
    switch(*s){
		case Symbole::OPERATEUR_ADD:
			a->pushSymbole(s);
			a->pushEtat(new Etat22());
			a->decaler();
			break;
		case Symbole::POINT_VIR:
			{
#ifdef MAP
	std::cout << "Reduction Instr -> ecrire expr" << std::endl;
#endif
				Expression* expr = dynamic_cast<Expression*> (a->popSymbole());
				Symbole* ecriture = new Affichage(*expr);
				a->popEtat();
				a->popEtat();

				a->pushSymbole(ecriture);
				a->etatCourant()->transition(a, ecriture);
			}
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
	}
}
