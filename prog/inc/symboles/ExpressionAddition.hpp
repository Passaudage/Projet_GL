/*************************************************************************
                           ExpressionAddition  -  description
                             -------------------
    début                : dim. 13 mars 2016
*************************************************************************/

//--------- Interface de la classe <ExpressionAddition> (fichier ExpressionAddition.hpp) ------
#ifndef EXPRESSIONADDITION_H
#define EXPRESSIONADDITION_H

//--------------------------------------------------- Interfaces utilisées
#include "symboles/ExpressionBinaire.hpp"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <ExpressionAddition>
//
//
//------------------------------------------------------------------------ 

class ExpressionAddition : public ExpressionBinaire
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void afficher();
    virtual Expression* simplifier(Programme& programme);

    virtual ExpressionBinaire* construireExpression(Expression* exprGauche,
        Expression* exprDroite, bool oppose = false);

//------------------------------------------------- Surcharge d'opérateurs
    ExpressionAddition& operator=(
			const ExpressionAddition & unExpressionAddition) = delete;

//-------------------------------------------- Constructeurs - destructeur
    ExpressionAddition(
			const ExpressionAddition & unExpressionAddition) = delete;

    ExpressionAddition(Expression& exprgauche, Expression& exprDroite);

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

    int operation(int a, int b, bool oppose = false);


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

//----------------------------------------- Types dépendants de <ExpressionAddition>

#endif // EXPRESSIONADDITION_H

