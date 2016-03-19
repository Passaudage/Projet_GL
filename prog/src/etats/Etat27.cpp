#include <iostream>
#include "etats/Etat27.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/ExpressionParenthesee.hpp"

Etat27 Etat27::m_instance = Etat27();

Etat27::Etat27()
{
}

Etat27* Etat27::getInstance(){
	return &m_instance;
}


void Etat27::transition(Automate* a, Symbole* ) //réduction règle 18
{
#ifdef MAP
	std::cout << "Etat27 : Reduction F->(Expr)" << std::endl;
#endif
	Expression* exprinter = dynamic_cast<Expression*>(a->popSymbole());
	Symbole* expr = new ExpressionParenthesee(*exprinter);
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a->pushSymbole(expr);
	a->etatCourant()->transition(a, expr);
}
