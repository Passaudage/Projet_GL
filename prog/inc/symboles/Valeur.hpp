/*************************************************************************
                           Valeur  -  description
                             -------------------
    début                : dim. 13 mars 2016
*************************************************************************/

//--------- Interface de la classe <Valeur> (fichier Valeur.hpp) ------
#ifndef VALEUR_H
#define VALEUR_H

//--------------------------------------------------- Interfaces utilisées
#include "symboles/Expression.hpp"

#include <unordered_set>
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Valeur>
//
//
//------------------------------------------------------------------------ 

class Identifiant;

class Valeur : public Expression
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	int calculer(Programme &);
	int getValeur() const;
	void afficher();
	Expression* optimiser(Programme& programme);
    std::unordered_set<Identifiant*> getIdentifiants();
    bool estEvaluable(Programme& programme);

//------------------------------------------------- Surcharge d'opérateurs
    Valeur& operator=(const Valeur & unValeur) = delete;

//-------------------------------------------- Constructeurs - destructeur
    Valeur(const Valeur & unValeur) = delete;

    Valeur(int valeur);
//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
	int _valeur;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Valeur>

#endif // VALEUR_H

