#ifndef SYMBOLE_HPP
#define SYMBOLE_HPP

#include "SymboleType.hpp"

class Symbole
{
public:
	Symbole();
	~Symbole();

	// Surcharge permettant de faire un switch
	// sur un objet Symbole
	operator int();

protected:

	SymboleType _symboleType;

private:

};

#endif
