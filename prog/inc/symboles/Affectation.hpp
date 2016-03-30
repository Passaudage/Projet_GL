/*************************************************************************
                           Affectation  -  description
                             -------------------
    début                : mar. 15 mars 2016
*************************************************************************/

//--------- Interface de la classe <Affectation> (fichier Affectation.hpp) ------
#ifndef AFFECTATION_H
#define AFFECTATION_H

//--------------------------------------------------- Interfaces utilisées
#include "symboles/Identifiant.hpp"
#include "symboles/InstructionExpression.hpp"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Affectation>
//
//
//------------------------------------------------------------------------ 

class Affectation : public InstructionExpression
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void afficher();
	void effectuer(Programme& programme);
	void optimiser(Programme& programme);
//------------------------------------------------- Surcharge d'opérateurs
    Affectation& operator=(const Affectation & unAffectation) = delete;

//-------------------------------------------- Constructeurs - destructeur
    Affectation(const Affectation & unAffectation) = delete;

    Affectation(Expression& expr, Identifiant& identifiant);
	
	~Affectation();

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées
	static const std::string _keyword;
protected:
//----------------------------------------------------- Attributs protégés
	Identifiant& _identifiant;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Affectation>

#endif // AFFECTATION_H

