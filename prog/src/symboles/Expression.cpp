#include "symboles/Expression.hpp"

//Initialisation par défaut d'un symbole facteur car c'est 
Expression::Expression(Symbole::Type symboleType):
	Symbole(symboleType),
	_propagerDestruction(true)
{

}


Expression* Expression::horsParenthese()
{
	return this;
}

Expression* Expression::enleverParentheses()
{
	return horsParenthese();
}
Expression* Expression::simplifier(Programme&)
{
	return this;
}

void Expression::setPropagerDestruction(bool propager)
{
	_propagerDestruction = propager;
}
