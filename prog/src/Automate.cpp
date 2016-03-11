#include "Automate.hpp"

#include "Etat.hpp"
#include "Symbole.hpp"

Automate::Automate()
{
}

Automate::~Automate()
{

}


Programme* Automate::getProgramme()
{
	Programme* programme = nullptr;

	// appel au lexer
	// récupération du flux des symboles

	return programme;
}

void Automate::pushEtat(Etat* etat)
{
	_pileEtats.push(etat);
}

void Automate::pushSymbole(Symbole* symbole)
{
	_pileSymboles.push(symbole);
}

Etat* Automate::popEtat()
{
	Etat* etat = _pileEtats.top();
	_pileEtats.pop();

	return etat;
}

Symbole* Automate::popSymbole()
{
	Symbole* symbole = _pileSymboles.top();
	_pileSymboles.pop();

	return symbole;
}

Etat* Automate::etatCourant() const
{
	return _pileEtats.top();
}

Symbole* Automate::symboleCourant() const
{
	return _pileSymboles.top();
}
