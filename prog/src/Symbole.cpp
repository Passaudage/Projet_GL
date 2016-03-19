#include "Symbole.hpp"

#ifdef MAP
#include <iostream>
#endif

Symbole::Symbole(Symbole::Type symboleType):_symboleType(symboleType)
{
}

Symbole::operator int()
{
	return _symboleType;
}

Symbole::~Symbole()
{
}

void Symbole::setType(Type symboleType)
{
#ifdef MAP
	std::cout << "Type symbole : " << _symboleType << " => " << symboleType <<
		std::endl;
#endif
	_symboleType = symboleType;
}
