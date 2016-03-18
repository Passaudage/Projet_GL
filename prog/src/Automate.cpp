#include "Automate.hpp"

#include "Etat.hpp"
#include "Symbole.hpp"

#include "symboles/Programme.hpp"

#include "etats/Etat0.hpp"

Automate::Automate(std::string const& fichier_lutin) : _fichier_lutin(fichier_lutin),
	_lexer(fichier_lutin)
{
}

Automate::~Automate()
{
}


Programme* Automate::getProgramme()
{
	Programme* programme = nullptr;

	// on commence la valse des états


	Etat0* etatDebut = new Etat0();

	pushEtat(etatDebut);

	while(!_pileEtats.empty())
	{
		etatCourant()->transition(this, _lexer.lireSymboleCourant());
	}

	delete etatDebut;


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

void Automate::popEtat()
{
	Etat* etat = _pileEtats.top();
	_pileEtats.pop();

	delete etat;
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

Symbole* Automate::lireSymboleCourant()
{
	return _lexer.lireSymboleCourant();
}

Symbole* Automate::lireSymboleSuivant()
{
	return _lexer.lireSymboleSuivant();
}

bool Automate::decaler()
{
	return _lexer.decaler();
}
