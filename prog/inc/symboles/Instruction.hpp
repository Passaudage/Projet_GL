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

#include <unordered_set>
#include <string>

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Instruction>
//
//
//------------------------------------------------------------------------ 

class Identifiant;

class Instruction : public Symbole
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	virtual bool estSansEffet();
	virtual void effectuer(Programme& programme) = 0;
	virtual void afficher() = 0;
	virtual void optimiser(Programme&) = 0;
	virtual std::unordered_set<Identifiant*> const getVarUtilisees() = 0;
	virtual Identifiant const * getVarAffectees() = 0;


//------------------------------------------------- Surcharge d'opérateurs
    Instruction& operator=(const Instruction & unInstruction) = delete;

//-------------------------------------------- Constructeurs - destructeur
    Instruction(const Instruction & unInstruction) = delete;

    Instruction();

    virtual ~Instruction();

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Attributs protégés
//
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Instruction>

#endif // INSTRUCTION_H

