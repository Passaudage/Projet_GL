#include "Automate.hpp"

#include "Etat.hpp"
#include "Symbole.hpp"

#include "symboles/Programme.hpp"

#include "etats/Etat0.hpp"

#include <iostream>

Automate::Automate(std::string const& fichier_lutin) : _fichier_lutin(fichier_lutin),
	_lexer(fichier_lutin)
{
}

Automate::~Automate()
{
	while (!_pileSymboles.empty()) {
		delete _pileSymboles.top();
		_pileSymboles.pop();
	}
}


Programme* Automate::getProgramme()
{
	Programme* programme = nullptr;

	pushEtat(Etat0::getInstance());

	while(!_pileEtats.empty()) {
		etatCourant()->transition(this, _lexer.lireSymboleCourant());
	}

	programme = dynamic_cast<Programme*>(popSymbole());

	return programme;
}

Symbole* Automate::topSymbole()
{
	return _pileSymboles.top();
}

void Automate::pushEtat(Etat* etat)
{
	_pileEtats.push(etat);
}

void Automate::pushSymbole(Symbole* symbole)
{
#ifdef MAP
	std::cout << "Ajout de : " << int(*symbole) << std::endl;
#endif
	_pileSymboles.push(symbole);
}

void Automate::popEtat()
{
	//~ Etat* etat = _pileEtats.top();
	_pileEtats.pop();
	//std::cout << "  pile- : " << _pileEtats.size() << std::endl;

	//~ delete etat;
}

Symbole* Automate::popSymbole()
{
	Symbole* symbole = _pileSymboles.top();
	_pileSymboles.pop();
#ifdef MAP
	std::cout << "depile " << int(*symbole) << std::endl;
#endif

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
#ifdef MAP
	std::cout << "Decalage de la tête de lecture de l'automate" << std::endl;
#endif
	return _lexer.decaler();
}
