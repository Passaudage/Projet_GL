/*************************************************************************
                           ExpressionBinaire  -  description
                             -------------------
    début                : dim. 13 mars 2016
*************************************************************************/

//--------- Interface de la classe <ExpressionBinaire> (fichier ExpressionBinaire.cpp) ------
#ifndef EXPRESSIONBINAIRE_H
#define EXPRESSIONBINAIRE_H

//--------------------------------------------------- Interfaces utilisées
#include "symboles/Expression.hpp"
#include <unordered_set>
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <ExpressionBinaire>
//
//
//------------------------------------------------------------------------ 

class Identifiant;

class ExpressionBinaire : public Expression
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	virtual int calculer(Programme &) = 0;
	virtual void afficher() = 0;
    virtual std::unordered_set<Identifiant*> getIdentifiants();
    bool estEvaluable(Programme& programme);

//------------------------------------------------- Surcharge d'opérateurs
    ExpressionBinaire& operator=(const ExpressionBinaire & unExpressionBinaire) =
		delete;

//-------------------------------------------- Constructeurs - destructeur
    ExpressionBinaire(const ExpressionBinaire & unExpressionBinaire) = delete;

    ExpressionBinaire(Expression& exprGauche, Expression& exprDroite);

    virtual ~ExpressionBinaire();

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
	Expression* _exprGauche;
	Expression* _exprDroite;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//-------------------------------- Types dépendants de <ExpressionBinaire>

#endif // EXPRESSIONBINAIRE_H

