#include "symboles/Programme.hpp"

#include "symboles/Declarations.hpp"

Programme::Programme(Declarations* declarations) : Symbole(PROGRAMME),
	_declarations(declarations)
{
}

Programme::~Programme()
{
	delete _declarations;
	// delete _instructions;
}


void Programme::afficher()
{
	// TODO
}

void Programme::transformer()
{
	// TODO
}

void Programme::executer()
{
	// TODO
}

void Programme::analyser()
{
	// TODO
}

int Programme::getValeur(std::string const& identifiant) const
{
	return _declarations->getValeur(identifiant);
}