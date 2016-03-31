#include "symboles/Instructions.hpp"
#include <iostream>
void Instructions::afficher()
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

void Instructions::optimiser(Programme & programme)
{
	std::list<Instruction*>::iterator it = _instructions.begin();
	while (it != _instructions.end()) {
		(*it)->optimiser(programme);
		if ((*it)->estSansEffet()) {
			delete *it;
			_instructions.erase(it++);
		} else {
			it++;
		}
	}
}

std::list<Instruction*>& Instructions::getInstructions()
{
	return _instructions;
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
