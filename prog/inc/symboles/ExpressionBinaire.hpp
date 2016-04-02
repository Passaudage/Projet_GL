#ifndef EXPRESSIONBINAIRE_H
#define EXPRESSIONBINAIRE_H

#include "symboles/Expression.hpp"
#include <unordered_set>


class Identifiant;

/*
 * Une expression binaire correspond à l'une des opérations
 * suivantes : +, -, *, /, toutes d'arité deux.
 * L'opérateur associé peut être commutatif, et comporte nécessairement
 * un élément neutre.
 */
class ExpressionBinaire : public Expression
{

public:

    ExpressionBinaire(const ExpressionBinaire & unExpressionBinaire) = delete;
    ExpressionBinaire& operator=(const ExpressionBinaire & unExpressionBinaire) =
        delete;

    /*
     * Ici, operation correspond soit à la paire d'opérateurs + et -,
     * soit * et /.
     */
    ExpressionBinaire(Expression& exprGauche, Expression& exprDroite,
        bool commutatif, int element_neutre, Symbole::Type operation);

    virtual ~ExpressionBinaire();


	virtual int calculer(Programme &);
	virtual void afficher() = 0;

    /*
     * Renvoie l'ensemble des identifiants présents dans l'expression.
     */
    virtual std::unordered_set<Identifiant*> getIdentifiants();

    /*
     * Renvoie vrai lorsque l'expression ne comporte que des 
     * nombres ou des constantes.
     */
    bool estEvaluable(Programme& programme);

    /*
     * Assure que l'expression retournée est bien formée, c'est à dire,
     * que tous les opérateurs binaires utilisés sont bien sous la forme
     * associative voulue.
     */
    Expression* enleverParentheses();

    /*
     * Ajoute, de manière à lever les ambiguïtés de lecture, des parenthèses
     * lorsque ceci est nécessaire.
     */
    virtual void ajouterParentheses();

    /*
     * Permet d'obtenir respectivement la partie gauche et la partie droite
     * de l'expression binaire.
     */
    Expression* getGauche();
    Expression* getDroite();


    bool commutatif();
    Symbole::Type getOperation();

    /*
     * Utile pour l'optimisation : de manière à détruire des expressions
     * binaires qui ne sont plus utilisées mais dont la partie gauche et
     * droite ont été utilisées autre part, il est nécessaire d'invalider
     * ces pointeurs pour détruire correctement l'objet.
     */
    void invaliderExpression();

    /*
     * Procède à l'optimisation de l'expression courante.
     * Le premier élément de la paire correspond à l'expression destinée
     * à remplacer l'ancienne.
     * Le second élément est présent uniquement lorsque remonter vaut vrai,
     * et correspond à un élément à remonter dans l'arbre de l'expression
     * pour simplifier l'expression parente.
     */
    virtual std::pair<Expression*, Expression*> optimiser(Programme& programme,
        bool remonter = false);

    /*
     * Lorsque oppose vaut faux, construit une expression binaire correspondant
     * à l'opérateur courant.
     * Si oppose vaut vrai, c'est l'opérateur opposé qui est associé à
     * l'expression binaire retournée.
     */
    virtual ExpressionBinaire* construireExpression(Expression* exprGauche,
        Expression* exprDroite, bool oppose = false) = 0;

protected:

	Expression* _exprGauche;
	Expression* _exprDroite;

    bool const _commutatif;
    int const _element_neutre;
    Symbole::Type const _operation;
    bool _uneFois;

    virtual int operation(int a, int b, bool oppose = false) = 0;

    bool estValeurConstante(Expression* expr, Programme& programme);
    Expression* simplifierElementNeutre(Programme& programme);


};

#endif // EXPRESSIONBINAIRE_H

