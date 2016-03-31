#include "symboles/Instructions.hpp"
#include <iostream>

#include <unordered_map>
#include <unordered_set>
#include <algorithm>

#include "symboles/Affichage.hpp"

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
	std::list<Instruction*>::iterator it;
	for (it = _instructions.begin() ; it != _instructions.end() ; it++) {
		(*it)->optimiser(programme);
	}
}

std::list<Instruction*>& Instructions::getInstructions()
{
	return _instructions;
}

void Instructions::optimiserInstructions()
{
	std::unordered_map<Instruction*, std::unordered_set<Identifiant*>>
		instructionsATraiter;

	std::unordered_set<Instruction*> instructionsADetruire;
	std::unordered_set<Affichage*> affichages;

	// par défaut, toutes les instructions sont susceptibles
	// d'être détruites
	instructionsADetruire.insert(_instructions.begin(),
		_instructions.end());

	// on va traiter au moins les instructions d'affichage
	for(Affichage* affichage : affichages) {
		instructionsATraiter.insert(
			std::pair<Instruction*, std::unordered_set<Identifiant*>>(
				affichage, affichage->getVarUtilisees())
			);
	}

	// on traite les instructions dont on doit résoudre les dépendances
	while(!instructionsATraiter.empty()) {

		std::pair<Instruction*, std::unordered_set<Identifiant*>> paire =
			*(instructionsATraiter.begin());

		std::list<Instruction*>::iterator itInstr =
			std::find(_instructions.begin(), _instructions.end(), paire.first);

		// tant qu'il reste des variables (dépendances) à trouver
		while(!paire.second.empty()) {

			// on remonte dans les instructions
			// sauf si on a atteint le début
			if(itInstr == _instructions.begin())
				break;

			itInstr--;

			Identifiant* varAffectee = (*itInstr)->getVarAffectees();

			if(varAffectee != nullptr) {
				std::unordered_set<Identifiant*>::iterator itId;

				itId = paire.second.find(varAffectee);

				if(itId != paire.second.end()) {
					// on a trouvé une dépendance

					// on enlève la variable de la
					// liste de dépendance courante
					paire.second.erase(itId);

					std::unordered_set<Identifiant*> varUtilisees =
						(*itInstr)->getVarUtilisees();

					if(varUtilisees.empty()) {
						// on rajoute l'instruction courante
						// s'il y a d'autres dépendances à récupérer

						instructionsATraiter.insert(
							std::pair<Instruction*, std::unordered_set<Identifiant*>>(
								*itInstr, varUtilisees)
							);
					}
				}
			}
		}
	}

	// on détruit les instructions qu'il faut détruire

	for(Instruction* instruction : instructionsADetruire) {
		_instructions.erase(std::find(_instructions.begin(), _instructions.end(), instruction));
		delete instruction;
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
