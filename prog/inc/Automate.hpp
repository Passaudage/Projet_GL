#ifndef AUTOMATE_HPP
#define AUTOMATE_HPP

#include <stack>

class Symbole;
class Etat;

class Automate
{
public:
	Automate();
	~Automate();

	void pushEtat(Etat* etat);
	void pushSymbole(Symbole* symbole);

	Etat* popEtat();
	Symbole* popSymbole();

	Etat* etatCourant() const;
	Symbole* symboleCourant() const;

private:
	std::stack<Symbole*> _pileSymboles;
	std::stack<Etat*> _pileEtats;
};

#endif
