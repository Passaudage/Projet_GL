#include "Symbole.hpp"

#ifdef MAP
#include <iostream>
#endif

Symbole::Symbole(Symbole::Type symboleType):_symboleType(symboleType),
	_initType(symboleType)
{
	_position.ligne = -1;
	_position.caractere = -1;
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
	return _position.ligne;
}
int Symbole::getCaractere()
{
	return _position.caractere;
}

Lexer::Position Symbole::getPosition()
{
	return _position;
}


void Symbole::setPosition(Lexer::Position position)
{
	_position = position;
}

int Symbole::getInitType()
{
	return _initType;
}