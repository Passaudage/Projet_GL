/*************************************************************************
                           Declarations  -  description
                             -------------------
    début                : mer. 16 mars 2016
*************************************************************************/

//--------- Interface de la classe <Declarations> (fichier Declarations.hpp) ------
#ifndef DECLARATIONS_H
#define DECLARATIONS_H

//--------------------------------------------------- Interfaces utilisées
#include "Symbole.hpp"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Declarations>
//
//
//------------------------------------------------------------------------ 

class Declarations : public Symbole
{
//----------------------------------------------------------------- PUBLIC

public:
//------------------------------------------------------ Classes publiques

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs
    Declarations& operator=(const Declarations & unDeclarations) = delete;

//-------------------------------------------- Constructeurs - destructeur
    Declarations(const Declarations & unDeclarations) = delete;

    Declarations();

    virtual ~Declarations();

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

//----------------------------------------- Types dépendants de <Declarations>

#endif // DECLARATIONS_H

