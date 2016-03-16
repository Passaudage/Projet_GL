#include "symboles/InstructionExpression.hpp"

InstructionExpression::InstructionExpression(Expression& expr):
	Instruction(),_expr(expr)
{
}

InstructionExpression::~InstructionExpression()
{
	delete &_expr;
}
