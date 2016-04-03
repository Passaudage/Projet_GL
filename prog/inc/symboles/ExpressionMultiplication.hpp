/*************************************************************************
                           ExpressionMultiplication  -  description
                             -------------------
    début                : dim. 13 mars 2016
*************************************************************************/

//--------- Interface de la classe <ExpressionMultiplication> (fichier ExpressionMultiplication.hpp) ------
#ifndef EXPRESSIONMULTIPLICATION_H
#define EXPRESSIONMULTIPLICATION_H

//--------------------------------------------------- Interfaces utilisées
#include "symboles/ExpressionBinaire.hpp"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <ExpressionMultiplication>
//
//
//------------------------------------------------------------------------ 

class ExpressionMultiplication : public ExpressionBinaire
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void afficher();

    virtual ExpressionBinaire* construireExpression(Expression* exprGauche,
        Expression* exprDroite, bool oppose = false);

    virtual Expression* simplifier(Programme& programme);

//------------------------------------------------- Surcharge d'opérateurs
    ExpressionMultiplication& operator=(
			const ExpressionMultiplication & unExpressionMultiplication) = delete;

//-------------------------------------------- Constructeurs - destructeur
    ExpressionMultiplication(
			const ExpressionMultiplication & unExpressionMultiplication) = delete;

    ExpressionMultiplication(Expression& exprgauche, Expression& exprDroite);

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

//----------------------------------------- Types dépendants de <ExpressionMultiplication>

#endif // EXPRESSIONMULTIPLICATION_H

