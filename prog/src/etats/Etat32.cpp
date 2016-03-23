#include <iostream>
#include "etats/Etat32.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/ExpressionMultiplication.hpp"
#include "symboles/ExpressionDivision.hpp"
#include "symboles/SymbolesTerminaux.hpp"
#include "symboles/Expression.hpp"

#include "Erreurs.hpp"

Etat32 Etat32::m_instance = Etat32();

Etat32::Etat32()
{
}

Etat32* Etat32::getInstance(){
	return &m_instance;
}


void Etat32::transition(Automate* a, Symbole* ) //réduction règle 16
{
#ifdef MAP
	std::cout << "Etat32" << std::endl;
#endif
	Expression* droite = dynamic_cast<Expression*> (a->popSymbole());
	OperateurMult* opM = dynamic_cast<OperateurMult*> (a->popSymbole());
	Expression* gauche = dynamic_cast<Expression*> (a->popSymbole());
	Expression* terme;
	
	if (opM->estMultiplie())
		terme = new ExpressionMultiplication(*gauche, *droite);
	else
		terme = new ExpressionDivision(*gauche, *droite);
	
	terme->setType(Symbole::Type::TERME);
	a->pushSymbole(terme);

	a->popEtat();
	a->popEtat();
	a->popEtat();

	a->etatCourant()->transition(a, terme);
}
