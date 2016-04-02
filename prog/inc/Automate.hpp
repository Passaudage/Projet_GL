#ifndef AUTOMATE_HPP
#define AUTOMATE_HPP

#include <stack>
#include <string>

#include "Lexer.hpp"

class Symbole;
class Etat;

class Programme;

/*
 * Représente l'automate. C'est cette classe qui initie le défilement des
 * états. Elle possède la pile de symboles ainsi que la pile d'états.
 *
 * Le lexer est encapsulé dans cette classe.
 */
class Automate
{
public:
	Automate(std::string const& fichier_lutin);
	~Automate();

	/*
	 * Retourne la classe correspondant
	 * à la représentation du code Lutin.
	 */
	Programme* getProgramme();

	/*
	 * Permet de gérer la pile d'états.
	 */
	void pushEtat(Etat* etat);
	void popEtat();
	Etat* etatCourant() const;

	/*
	 * Permet de gérer la pile de symboles.
	 */
	void pushSymbole(Symbole* symbole);
	Symbole* popSymbole();
	Symbole* topSymbole();

	/*
	 * Relatif aux actions du Lexer.
	 */
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
