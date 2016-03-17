#include "symboles/SymbolesTerminaux.hpp"

OperateurMult::OperateurMult(bool multiplie):_multiplie(multiplie)
{
}

bool OperateurMult::estMultiplie()
{
	return _multiplie;
}
