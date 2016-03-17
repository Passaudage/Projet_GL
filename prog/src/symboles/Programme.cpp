#include "symboles/Programme.hpp"

#include "symboles/Declarations.hpp"

Programme::Programme(Declarations* declarations) : Symbole(PROGRAMME),
	_declarations(declarations)
{
}


void Programme::afficher()
{

}

void Programme::transformer()
{

}

void Programme::executer()
{

}

void Programme::analyser()
{

}

int Programme::getValeur(std::string const& identifiant) const
{
	return _declarations->getValeur(identifiant);
}