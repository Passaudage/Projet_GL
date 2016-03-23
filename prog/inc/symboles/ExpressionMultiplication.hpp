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
	int calculer(Programme& programme);
	void afficher();
	Expression* optimiser(Programme& programme);

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

