#include "symboles/Identifiant.hpp"

Identifiant::Identifiant(std::string const& identifiant) : Expression(IDENTIFIANT), _identifiant(identifiant)
{
}

int Identifiant::calculer(Programme& programme)
{
	return programme.getValeur(_identifiant);
}

std::string const& Identifiant::get() const
{
	return _identifiant;
}
