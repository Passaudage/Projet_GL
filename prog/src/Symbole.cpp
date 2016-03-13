#include "Symbole.hpp"

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
