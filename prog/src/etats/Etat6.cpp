#include <iostream>

#include "etats/Etat6.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/Lecture.hpp"
#include "symboles/Identifiant.hpp"

#include "symboles/Declarations.hpp"

Etat6 Etat6::m_instance = Etat6();

Etat6::Etat6()
{
}

Etat6* Etat6::getInstance(){
	return &m_instance;
}


void Etat6::transition(Automate* a, Symbole* ) //réduction de la règle 11
{
#ifdef MAP
	std::cout << "Etat6 : réduction I -> lire id" << std::endl;
#endif
	Identifiant* id = (Identifiant*) a->popSymbole();
	Symbole* lecture = new Lecture(*id);

	((Declarations*) a->symboleCourant())->signerAffecter(id);

	a-> popEtat();
	a-> popEtat();
	a->pushSymbole(lecture);
	a->etatCourant()->transition(a, lecture);
}
