/*************************************************************************
                           InstructionExpression  -  description
                             -------------------
    début                : mar. 15 mars 2016
*************************************************************************/

//--------- Interface de la classe <InstructionExpression> (fichier InstructionExpression.hpp) ------
#ifndef INSTRUCTIONEXPRESSION_H
#define INSTRUCTIONEXPRESSION_H

//--------------------------------------------------- Interfaces utilisées
#include "symboles/Instruction.hpp"
#include "symboles/Expression.hpp"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <InstructionExpression>
//
//
//------------------------------------------------------------------------ 

class InstructionExpression : public Instruction
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	virtual void effectuer(Programme& programme) = 0;
	virtual void afficher() = 0;

//------------------------------------------------- Surcharge d'opérateurs
    InstructionExpression& operator=(const InstructionExpression & unInstructionExpression) = delete;

//-------------------------------------------- Constructeurs - destructeur
    InstructionExpression(const InstructionExpression & unInstructionExpression) = delete;

    InstructionExpression(Expression& expr);

    virtual ~InstructionExpression();

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
	Expression* _expr;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <InstructionExpression>

#endif // INSTRUCTIONEXPRESSION_H

