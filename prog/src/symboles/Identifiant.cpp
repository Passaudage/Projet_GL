#include "symboles/SymbolesTerminaux.hpp"

Identifiant::Identifiant(std::string const& identifiant) : _identifiant(identifiant)
{
}

std::string const& Identifiant::get() const
{
	return _identifiant;
}
