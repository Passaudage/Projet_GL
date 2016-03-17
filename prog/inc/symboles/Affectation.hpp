/*************************************************************************
                           Affectation  -  description
                             -------------------
    début                : mar. 15 mars 2016
*************************************************************************/

//--------- Interface de la classe <Affectation> (fichier Affectation.hpp) ------
#ifndef AFFECTATION_H
#define AFFECTATION_H

//--------------------------------------------------- Interfaces utilisées
#include "../symboles/InstructionExpression.hpp"
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
	void effectuer(Programme& programme);

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

