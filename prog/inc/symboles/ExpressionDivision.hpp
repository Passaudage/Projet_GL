/*************************************************************************
                           ExpressionDivision  -  description
                             -------------------
    début                : dim. 13 mars 2016
*************************************************************************/

//--------- Interface de la classe <ExpressionDivision> (fichier ExpressionDivision.hpp) ------
#ifndef EXPRESSIONDIVISION_H
#define EXPRESSIONDIVISION_H

//--------------------------------------------------- Interfaces utilisées
#include "symboles/ExpressionBinaire.hpp"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <ExpressionDivision>
//
//
//------------------------------------------------------------------------ 

class ExpressionDivision : public ExpressionBinaire
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	int calculer(Programme& programme);
	void afficher();

//------------------------------------------------- Surcharge d'opérateurs
    ExpressionDivision& operator=(
			const ExpressionDivision & unExpressionDivision) = delete;

//-------------------------------------------- Constructeurs - destructeur
    ExpressionDivision(
			const ExpressionDivision & unExpressionDivision) = delete;

    ExpressionDivision(Expression& exprgauche, Expression& exprDroite);

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

//----------------------------------------- Types dépendants de <ExpressionDivision>

#endif // EXPRESSIONDIVISION_H

