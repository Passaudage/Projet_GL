#include "Symbole.hpp"

#ifdef MAP
#include <iostream>
#endif

Symbole::Symbole(Symbole::Type symboleType):_symboleType(symboleType),
	_ligne(-1), _caractere(-1)
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

int Symbole::getLigne()
{
	return _ligne;
}
int Symbole::getCaractere()
{
	return _caractere;
}


void Symbole::setPosition(Lexer::Position position)
{
	_ligne = position.ligne;
	_caractere = position.caractere;
}