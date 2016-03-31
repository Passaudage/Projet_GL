#include <iostream>
#include "etats/Etat23.hpp"
#include "etats/Etat29.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/ExpressionAddition.hpp"
#include "symboles/ExpressionSoustraction.hpp"
#include "symboles/SymbolesTerminaux.hpp"
#include "symboles/Expression.hpp"

#include "Erreurs.hpp"

Etat23 Etat23::m_instance;

Etat23::Etat23()
{
}

Etat23* Etat23::getInstance(){
	return &m_instance;
}


void Etat23::transition(Automate* a, Symbole* s)
{
#ifdef MAP
	std::cout << "Etat23" << std::endl;
#endif
    switch(*s){
		case Symbole::OPERATEUR_MUL:
			a->pushSymbole(s);
			a->pushEtat(Etat29::getInstance());
			a->decaler();
			break;
		case Symbole::POINT_VIR:
		case Symbole::PARENTHESE_FER:
		case Symbole::OPERATEUR_ADD:
			{
				Expression* expr_droit = (Expression*) a->popSymbole();
				OperateurAdd* operateur = (OperateurAdd*) a->popSymbole();
				Expression* expr_gauche = (Expression*) a->popSymbole();
				Expression* expr;
				if(operateur->estAddition()){
					expr = new ExpressionAddition(*expr_gauche, *expr_droit);
				} else {
					expr = new ExpressionSoustraction(*expr_gauche, *expr_droit);
				}
				delete operateur;
				expr->setType(Symbole::EXPRESSION);
				a->pushSymbole(expr);
				a->popEtat();
				a->popEtat();
				a->popEtat();
				a->etatCourant()->transition(a, expr);
			}
			break;
		default:
			throw ExceptionSymbole(s, ExceptionSymbole::symbole_non_attendu);
			break;
		}
}
