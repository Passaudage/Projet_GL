/*************************************************************************
                           ExpressionSoustraction  -  description
                             -------------------
    début                : dim. 13 mars 2016
*************************************************************************/

//--------- Interface de la classe <ExpressionSoustraction> (fichier ExpressionSoustraction.hpp) ------
#ifndef EXPRESSIONSOUSTRACTION_H
#define EXPRESSIONSOUSTRACTION_H

//--------------------------------------------------- Interfaces utilisées
#include "symboles/ExpressionBinaire.hpp"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <ExpressionSoustraction>
//
//
//------------------------------------------------------------------------ 

class ExpressionSoustraction : public ExpressionBinaire
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void afficher();

    virtual ExpressionBinaire* construireExpression(
        Expression* exprGauche, Expression* exprDroite, bool oppose = false);
    virtual Expression* simplifier(Programme& programme);

//------------------------------------------------- Surcharge d'opérateurs
    ExpressionSoustraction& operator=(
			const ExpressionSoustraction & unExpressionSoustraction) = delete;

//-------------------------------------------- Constructeurs - destructeur
    ExpressionSoustraction(
			const ExpressionSoustraction & unExpressionSoustraction) = delete;

    ExpressionSoustraction(Expression& exprgauche, Expression& exprDroite);

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

//----------------------------------------- Types dépendants de <ExpressionSoustraction>

#endif // EXPRESSIONSOUSTRACTION_H

