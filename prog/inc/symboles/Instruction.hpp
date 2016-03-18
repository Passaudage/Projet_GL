/*************************************************************************
                           Instruction  -  description
                             -------------------
    début                : mar. 15 mars 2016
*************************************************************************/

//--------- Interface de la classe <Instruction> (fichier Instruction.hpp) ------
#ifndef INSTRUCTION_H
#define INSTRUCTION_H

//--------------------------------------------------- Interfaces utilisées
#include "Symbole.hpp"
#include "symboles/Programme.hpp"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Instruction>
//
//
//------------------------------------------------------------------------ 

class Instruction : public Symbole
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	virtual void effectuer(Programme& programme) = 0;
	virtual void afficher() = 0;

//------------------------------------------------- Surcharge d'opérateurs
    Instruction& operator=(const Instruction & unInstruction) = delete;

//-------------------------------------------- Constructeurs - destructeur
    Instruction(const Instruction & unInstruction) = delete;

    Instruction();

    virtual ~Instruction();

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Instruction>

#endif // INSTRUCTION_H

