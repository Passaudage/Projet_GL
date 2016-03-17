#include "symboles/Identifiant.hpp"

Identifiant::Identifiant(std::string const& identifiant) : Expression(IDENTIFIANT), _identifiant(identifiant)
{
}

int Identifiant::calculer(Programme& programme)
{
	// TODO
	return 0;
}

std::string const& Identifiant::get() const
{
	return _identifiant;
}
