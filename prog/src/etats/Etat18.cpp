#include <iostream>
#include "etats/Etat18.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "symboles/Declarations.hpp"
#include "symboles/Identifiant.hpp"
#include "symboles/Valeur.hpp"

#include "Erreurs.hpp"

Etat18 Etat18::m_instance;

Etat18::Etat18()
{
}

Etat18* Etat18::getInstance(){
	return &m_instance;
}

void Etat18::transition(Automate* a, Symbole* ) //réduction de la règle 7
{
#ifdef MAP
	std::cout << "Etat18 : Reduction D -> D const IDC id=val;" << std::endl ;
#endif
    Valeur* val = dynamic_cast<Valeur*> (a->popSymbole());
    Identifiant* id = dynamic_cast<Identifiant*> (a->popSymbole());
	Declarations::IDC* idc = dynamic_cast<Declarations::IDC*> (a->popSymbole());
	Declarations* d = dynamic_cast<Declarations*> (a->symboleCourant());

#ifdef MAP
	std::cout << "Valeur : " << val->getValeur() << std::endl;;
#endif

	idc->ajouterConstante(id->get(), val->getValeur());
	d->enregistrerConstantes(*idc);
	delete val;
	delete id;
	delete idc;

	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();
	a-> popEtat();

	a->etatCourant()->transition(a, d);
}
