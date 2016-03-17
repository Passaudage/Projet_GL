#include "symboles/SymbolesTerminaux.hpp"

OperateurAdd::OperateurAdd(bool addition):_addition(addition)
{
}

bool OperateurAdd::estAddition()
{
	return _addition;
}
