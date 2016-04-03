#include "symboles/InstructionExpression.hpp"

InstructionExpression::InstructionExpression(Expression& expr):
	Instruction()
{
	_expr = &expr;
}

InstructionExpression::~InstructionExpression()
{
	delete _expr;
}

std::unordered_set<Identifiant*> const InstructionExpression::getVarUtilisees()
{
	return _expr->getIdentifiants();
}
