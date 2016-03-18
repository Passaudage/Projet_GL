#ifndef AUTOMATE_HPP
#define AUTOMATE_HPP

#include <stack>
#include <string>

#include "Lexer.hpp"

class Symbole;
class Etat;

class Programme;

class Automate
{
public:
	Automate(std::string const& fichier_lutin);
	~Automate();

	Programme* getProgramme();

	void pushEtat(Etat* etat);
	void pushSymbole(Symbole* symbole);

	void popEtat();
	Symbole* popSymbole();

	Etat* etatCourant() const;
	Symbole* symboleCourant() const;

	Symbole* lireSymboleCourant();
    Symbole* lireSymboleSuivant();

    bool decaler();

private:
	std::stack<Symbole*> _pileSymboles;
	std::stack<Etat*> _pileEtats;
	std::string _fichier_lutin;
	Lexer _lexer;
};

#endif
