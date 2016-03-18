#include "Etat23.h"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/ExpressionAddition.hpp"
#include "symboles/ExpressionSoustraction.hpp"

Etat23::Etat23()
{
    //ctor
}

Etat23::~Etat23()
{
    //dtor
}
void Etat23::transition(Automate* a, Symbole* s)
{
    switch(*s){
		case Symbole::OPERATEUR_MUL:
			a->pushSymbole(s);
			a->pushEtat(new Etat29());
			break;
		case Symbole::POINT_VIR:
		case Symbole::PARENTHESE_FER:
		case Symbole::POINT_VIR:
			Symbole* expr_droit= (Expression*) a->popSymbole();
			Symbole* operateur = (OperateurAdd*) a->popSymbole();
			Symbole* expr_gauche = (Expression*) a->popSymbole();
			Symbole* expr;
			if(operateur.estAddition()){
				expr = new ExpressionAddition(*expr_gauche, *expr_droit);
			} else {
				expr = new ExpressionSoustraction(*expr_gauche, *expr_droit);
			}
			a->popEtat();
			a->popEtat();
			a->popEtat();
			a->etatCourant()->transition(a, expr);
			break;
		default:
			std::cerr<<"erreur, lecture non conforme à la grammaire"<< std::endl;
			break;
}
