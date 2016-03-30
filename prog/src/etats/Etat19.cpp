#include <iostream>
#include "etats/Etat19.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/Declarations.hpp"
#include "symboles/Valeur.hpp"
#include "symboles/Identifiant.hpp"

#include "Erreurs.hpp"

Etat19 Etat19::m_instance = Etat19();

Etat19::Etat19()
{
}

Etat19* Etat19::getInstance(){
	return &m_instance;
}


void Etat19::transition(Automate* a, Symbole* )
{
#ifdef MAP
	std::cout << "Etat19" << std::endl;
#endif
	Valeur* val = dynamic_cast<Valeur*> (a->popSymbole());
	Identifiant* id = dynamic_cast<Identifiant*> (a->popSymbole());
	Declarations::IDC* idc = dynamic_cast<Declarations::IDC*> (a->symboleCourant());
	
	idc->ajouterConstante(id->get(), val->getValeur());

	delete val;
	delete id;

	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	
	a->etatCourant()->transition(a, idc);
}
