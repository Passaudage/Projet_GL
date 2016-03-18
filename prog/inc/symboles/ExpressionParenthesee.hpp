/*************************************************************************
                           ExpressionParenthesee  -  description
                             -------------------
    début                : dim. 13 mars 2016
*************************************************************************/

// Interface de la classe <ExpressionParenthesee> 
// (fichier ExpressionParenthesee.hpp) ------
#ifndef EXPRESSIONPARENTHESEE_H
#define EXPRESSIONPARENTHESEE_H

//--------------------------------------------------- Interfaces utilisées
#include "symboles/Expression.hpp"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <ExpressionParenthesee>
//
//
//------------------------------------------------------------------------ 

class ExpressionParenthesee : public Expression
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	int calculer(Programme & programme);
	void afficher();

//------------------------------------------------- Surcharge d'opérateurs
    ExpressionParenthesee& operator=(
			const ExpressionParenthesee & unExpressionParenthesee) = delete;

//-------------------------------------------- Constructeurs - destructeur
    ExpressionParenthesee(
			const ExpressionParenthesee & unExpressionParenthesee) = delete;

    ExpressionParenthesee(Expression& exprInter);

    ~ExpressionParenthesee();

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
	Expression& _exprInter;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <ExpressionParenthesee>

#endif // EXPRESSIONPARENTHESEE_H

