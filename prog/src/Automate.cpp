#include "../inc/Automate.hpp"

#include "../inc/Etat.hpp"
#include "../inc/Symbole.hpp"

Automate::Automate()
{
}

Automate::~Automate()
{

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

Etat* etatCourant()
{
	return _pileEtats.pop();
}

Symbole* symboleCourant()
{
	return _pileSymboles();
}
