#include "symboles/SymbolesTerminaux.hpp"

OperateurAdd::OperateurAdd(bool addition):Symbole(Symbole::Type::OPERATEUR_ADD),
	_addition(addition)
{
}

bool OperateurAdd::estAddition()
{
	return _addition;
}
