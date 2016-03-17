/*************************************************************************
                           Lecture  -  description
                             -------------------
    début                : mar. 15 mars 2016
*************************************************************************/

//--------- Interface de la classe <Lecture> (fichier Lecture.hpp) ------
#ifndef LECTURE_H
#define LECTURE_H

//--------------------------------------------------- Interfaces utilisées
#include "symboles/Instruction.hpp"
#include "symboles/Identifiant.hpp"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Lecture>
//
//
//------------------------------------------------------------------------ 

class Lecture : public Instruction
{
//----------------------------------------------------------------- PUBLIC
	
public:
//----------------------------------------------------- Méthodes publiques
	void effectuer(Programme & programme);

//------------------------------------------------- Surcharge d'opérateurs
    Lecture& operator=(const Lecture & unLecture) = delete;

//-------------------------------------------- Constructeurs - destructeur
    Lecture(const Lecture & unLecture) = delete;

    Lecture(Identifiant& identifiant);

    virtual ~Lecture();

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
	Identifiant& _identifiant();

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Lecture>

#endif // LECTURE_H

