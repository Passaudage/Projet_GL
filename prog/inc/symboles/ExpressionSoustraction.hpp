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
	int calculer(Programme& programme);
	void afficher();
	Expression* optimiser(Programme& programme);

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

