#include "symboles/Programme.hpp"

#include "symboles/Declarations.hpp"
#include "symboles/Instructions.hpp"

Programme::Programme(Declarations* declarations, Instructions* instructions) : 
	Symbole(PROGRAMME),
	_declarations(declarations),
	_instructions(instructions)
{
}

Programme::~Programme()
{
	delete _declarations;
	delete _instructions;
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
	_instructions->executer(*this);
}

void Programme::analyser()
{
	// TODO
}

int Programme::getValeur(std::string const& identifiant) const
{
	return _declarations->getValeur(identifiant);
}

void Programme::setValeur(std::string const& identifiant, int valeur)
{
	_declarations->setValeur(identifiant, valeur);
}
