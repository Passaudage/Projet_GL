/*************************************************************************
                           Instructions  -  description
                             -------------------
    début                : jeu. 17 mars 2016
*************************************************************************/

//--------- Interface de la classe <Instructions> (fichier Instructions.hpp) ------
#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

//--------------------------------------------------- Interfaces utilisées
#include "Symbole.hpp"
#include "symboles/Instruction.hpp"
#include "symboles/Programme.hpp"
#include <list>

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Instructions>
//
//
//------------------------------------------------------------------------ 

class Instructions : public Symbole
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void ajouteInstruction(Instruction* instruction);
	void executer(Programme & programme);
	void affiche();

//------------------------------------------------- Surcharge d'opérateurs
    Instructions& operator=(const Instructions & unInstructions) = delete;

//-------------------------------------------- Constructeurs - destructeur
    Instructions(const Instructions & unInstructions) = delete;

    Instructions();

    virtual ~Instructions();

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
	std::list<Instruction*> _instructions;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Instructions>

#endif // INSTRUCTIONS_H

