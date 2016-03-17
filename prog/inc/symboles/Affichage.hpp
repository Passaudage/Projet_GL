/*************************************************************************
                           Affichage  -  description
                             -------------------
    début                : jeu. 17 mars 2016
*************************************************************************/

//--------- Interface de la classe <Affichage> (fichier Affichage.hpp) ------
#ifndef AFFICHAGE_H
#define AFFICHAGE_H

//--------------------------------------------------- Interfaces utilisées
#include "symboles/InstructionExpression.hpp"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Affichage>
//
//
//------------------------------------------------------------------------ 

class Affichage : public InstructionExpression
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void effectuer(Programme& programme);

//------------------------------------------------- Surcharge d'opérateurs
    Affichage& operator=(const Affichage & unAffichage) = delete;

//-------------------------------------------- Constructeurs - destructeur
    Affichage(const Affichage & unAffichage) = delete;

    Affichage(Expression& expr);

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

//----------------------------------------- Types dépendants de <Affichage>

#endif // AFFICHAGE_H

