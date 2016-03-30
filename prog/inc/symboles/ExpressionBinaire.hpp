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
	virtual int calculer(Programme &);
	virtual void afficher() = 0;

    // Renvoie l'ensemble non ordonné des identifiants présents
    // dans l'expression
    virtual std::unordered_set<Identifiant*> getIdentifiants();

    bool estEvaluable(Programme& programme);

    Expression* enleverParentheses();
    virtual void ajouterParentheses();

    Expression* getGauche();
    Expression* getDroite();

    // Renvoie vrai si l'opérateur considéré est commutatif, faux sinon.
    bool commutatif();
    Symbole::Type getOperation();

    // Attention : associe nullptr aux expressions
    // gauche et droite de manière à éviter la propagation
    // d'éventuels delete
    void invaliderExpression();

    virtual std::pair<Expression*, Expression*> optimiser(Programme& programme,
        bool remonter = false);

    virtual ExpressionBinaire* construireExpression(Expression* exprGauche,
        Expression* exprDroite, bool oppose = false) = 0;

//------------------------------------------------- Surcharge d'opérateurs
    ExpressionBinaire& operator=(const ExpressionBinaire & unExpressionBinaire) =
		delete;

//-------------------------------------------- Constructeurs - destructeur
    ExpressionBinaire(const ExpressionBinaire & unExpressionBinaire) = delete;

    ExpressionBinaire(Expression& exprGauche, Expression& exprDroite,
        bool commutatif, int element_neutre, Symbole::Type operation);

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

    bool const _commutatif;
    int const _element_neutre;
    Symbole::Type const _operation;
    bool _uneFois;

    virtual int operation(int a, int b, bool oppose = false) = 0;

    bool estValeurConstante(Expression* expr, Programme& programme);
    Expression* simplifierElementNeutre(Programme& programme);

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//-------------------------------- Types dépendants de <ExpressionBinaire>

#endif // EXPRESSIONBINAIRE_H

