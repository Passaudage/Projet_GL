#include "symboles/SymbolesTerminaux.hpp"

OperateurMult::OperateurMult(bool multiplie):Symbole(Symbole::Type::OPERATEUR_MUL),_multiplie(multiplie)
{
}

bool OperateurMult::estMultiplie()
{
	return _multiplie;
}
