#include "symboles/Instructions.hpp"
#include <iostream>

#include <unordered_map>
#include <unordered_set>
#include <algorithm>

#include "symboles/Affichage.hpp"
#include "symboles/Identifiant.hpp"

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

void Instructions::optimiserInstructions()
{
	std::unordered_map<Instruction*, std::unordered_set<std::string>>
		instructionsATraiter;

	std::unordered_set<Instruction*> instructionsADetruire;
	std::unordered_set<Affichage*> affichages;

	// par défaut, toutes les instructions sont susceptibles
	// d'être détruites
	instructionsADetruire.insert(_instructions.begin(),
		_instructions.end());

	affichages = Affichage::getAffichages();

	// on va traiter au moins les instructions d'affichage
	for(Affichage* affichage : affichages) {
		std::unordered_set<std::string> dependances;
		std::unordered_set<Identifiant*> dependancesId =
			affichage->getVarUtilisees();

		for(Identifiant* id : dependancesId) {
			dependances.insert(id->get());
		}

		instructionsATraiter.insert(
			std::pair<Instruction*, std::unordered_set<std::string>>(
				affichage, dependances)
			);
	}

	// on traite les instructions dont on doit résoudre les dépendances
	while(!instructionsATraiter.empty()) {

		std::pair<Instruction*, std::unordered_set<std::string>> paire =
			*(instructionsATraiter.begin());

		std::list<Instruction*>::iterator itInstrInit =
			std::find(_instructions.begin(), _instructions.end(), paire.first);

		std::list<Instruction*>::iterator itInstr = itInstrInit;

#ifdef MAP
		std::cout << "-> ";
		paire.first->afficher();
		for(std::string id : paire.second) {
			std::cout << " " << id << std::endl;
		}
#endif

		// tant qu'il reste des variables (dépendances) à trouver
		while(!paire.second.empty()) {

			// on remonte dans les instructions
			// sauf si on a atteint le début
			if(itInstr == _instructions.begin())
				break;

			itInstr--;

#ifdef MAP
			std::cout << " trouvons les dependances !" << std::endl;
			(*itInstr)->afficher();
#endif

			Identifiant const* varAffecteeId = (*itInstr)->getVarAffectees();

			if(varAffecteeId != nullptr) {
				std::string varAffectee = varAffecteeId->get();

				std::unordered_set<std::string>::iterator itId;

				itId = paire.second.find(varAffectee);

				if(itId != paire.second.end()) {
#ifdef MAP
					std::cout << "Dépendance !" << std::endl;
#endif
					// on a trouvé une dépendance

					// on enlève la variable de la
					// liste de dépendances courantes
					paire.second.erase(itId);

					std::unordered_set<Identifiant*> varUtilisees =
						(*itInstr)->getVarUtilisees();

					if(!varUtilisees.empty()) {
#ifdef MAP
						std::cout << "d'autres dependances suivent" << std::endl;
#endif
						// on rajoute l'instruction courante
						// parce qu'il y a d'autres dépendances à récupérer
						std::unordered_set<std::string> dependances;

						for(Identifiant* id : varUtilisees) {
							dependances.insert(id->get());
						}

						instructionsATraiter.insert(
							std::pair<Instruction*, std::unordered_set<std::string>>(
								*itInstr, dependances)
							);
					} else {
						// l'instruction courante est donc à garder
						instructionsADetruire.erase(*itInstr);
					}
				}
			}
			
		}

		// s'il les dépendances ont toutes
		// été résolues
		// ou que l'on a parcouru l'ensemble des instructions
		// avant l'instruction courante, sans les résoudre
		if(paire.second.empty() ||
			itInstr == _instructions.begin()) {
			// on garde l'instruction
			instructionsADetruire.erase(*itInstrInit);
		}

		instructionsATraiter.erase(paire.first);
	}

	// on détruit les instructions qu'il faut détruire

	for(Instruction* instruction : instructionsADetruire) {
		_instructions.erase(std::find(_instructions.begin(), _instructions.end(), instruction));
		delete instruction;
	}

#ifdef MAP
	std::cout << "------" << std::endl;
#endif
}

std::unordered_set<std::string> Instructions::getIdentifiantsUtilises()
{
	std::unordered_set<std::string> identifiants;

	for(Instruction* instruction : _instructions) {
		std::unordered_set<Identifiant*> temp =
			instruction->getVarUtilisees();

		for(Identifiant* identifiant : temp)
			identifiants.insert(identifiant->get());
	}

	return identifiants;
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
