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

Etat20::~Etat20()
{
    //dtor
}
void Etat20::transition(Automate* a, Symbole* s)
{
	std::cout << "Etat20" << std::endl;
    switch(*s){
		case Symbole::OPERATEUR_ADD:
			a->pushSymbole(s);
			a->pushEtat(new Etat22());
			a->decaler();
			break;

// Vérifier les suivants de Instruction
		case Symbole::POINT_VIR:
			{
				Expression* expr = dynamic_cast<Expression*> (a->popSymbole());
				//a->popSymbole();
				Symbole* ecriture = new Affichage(*expr);
				a->popEtat();
				a->popEtat();
				a->etatCourant()->transition(a, ecriture);
			}
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
	}
}
