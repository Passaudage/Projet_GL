/*************************************************************************
                           Expression  -  description
                             -------------------
    début                : dim. 13 mars 2016
*************************************************************************/

//--------- Interface de la classe <Expression> (fichier Expression.hpp) ------
#ifndef EXPRESSION_H
#define EXPRESSION_H

//--------------------------------------------------- Interfaces utilisées
#include "Symbole.hpp"
#include "symboles/Programme.hpp"

#include <unordered_set>

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Expression>
//
//
//------------------------------------------------------------------------ 

class Identifiant;
class Expression;

class Expression : public Symbole
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	//Calcule la valeur de l'expression
	virtual int calculer(Programme & programme) = 0;
	virtual void afficher() = 0;
	virtual std::unordered_set<Identifiant*> getIdentifiants() = 0;

	virtual Expression* horsParenthese();
	virtual Expression* enleverParentheses();
	virtual void ajouterParentheses();

	virtual Expression* simplifier(Programme&);
	virtual std::pair<Expression*, Expression*> optimiser(Programme& programme, bool remonter = false) = 0;

	// renvoie vrai si la sous-expression "correspond" à une constante
	virtual bool estEvaluable(Programme& programme) = 0;
	
//------------------------------------------------- Surcharge d'opérateurs
    Expression& operator=(const Expression & unExpression)=delete ;

//-------------------------------------------- Constructeurs - destructeur
    Expression(const Expression & unExpression) = delete;

    Expression(Symbole::Type symboleType);
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

//----------------------------------------- Types dépendants de <Expression>

#endif // EXPRESSION_H

