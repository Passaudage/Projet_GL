#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "Symbole.hpp"
#include "symboles/Instruction.hpp"
#include "symboles/Programme.hpp"
#include <list>


/*
 * Cette classe stocke l'ensemble des instructions du programme.
 * Elle permet également d'effectuer l'exécution du programme,
 * ainsi que son optimisation.
 */
class Instructions : public Symbole
{

public:

    Instructions& operator=(const Instructions & unInstructions) = delete;
    Instructions(const Instructions & unInstructions) = delete;

    Instructions();
    virtual ~Instructions();


	void ajouteInstruction(Instruction* instruction);
	void executer(Programme & programme);
	void afficher();
	void optimiser(Programme & programme);

    std::list<Instruction*>& getInstructions();
    /*
     * Retourne l'ensemble des identifiants utilisés par les instructions.
     * Un identifiant utilisé correspond à un identifiant dont sa valeur
     * est nécessaire pour exécuter correctement au moins une instruction.
     * (présence en partie droite d'un affectation ou dans une instruction
     * d'affichage)
     */
    std::unordered_set<std::string> getIdentifiantsUtilises();

    /*
     * Optimise spécifiquement les dépendances entre les instructions.
     */
    void optimiserInstructions();

protected:

	std::list<Instruction*> _instructions;

};

#endif // INSTRUCTIONS_H

