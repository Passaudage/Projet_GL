#include "symboles/Instructions.hpp"

void Instructions::affiche()
{
	std::list<Instruction*>::iterator it;
	for (it = _instructions.begin() ; it != _instructions.end() ; it++) {
		(*it)->afficher();
	}
}

void Instructions::ajouteInstruction(Instruction* instruction)
{
	_instructions.push_back(instruction);
}

void Instructions::executer(Programme& programme)
{
	std::list<Instruction*>::iterator it;
	for (it = _instructions.begin() ; it != _instructions.end() ; it++) {
		(*it)->effectuer(programme);
	}
}

Instructions::Instructions():Symbole(Symbole::Type::INSTRUCTIONS)
{
}

Instructions::~Instructions()
{
	std::list<Instruction*>::iterator it;
	for (it = _instructions.begin() ; it != _instructions.end() ; it++) {
		delete *it;
	}
}
