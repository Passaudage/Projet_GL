/*************************************************************************
                           Programme  -  description
                             -------------------
    début                : dim. 13 mars 2016
*************************************************************************/

//--------- Interface de la classe <Programme> (fichier Programme.hpp) ------
#ifndef PROGRAMME_H
#define PROGRAMME_H

//--------------------------------------------------- Interfaces utilisées
#include "Symbole.hpp"
#include <string>

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Programme>
//
//
//------------------------------------------------------------------------ 

class Declarations;
class Instructions;

class Programme : public Symbole
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs
    Programme& operator=(const Programme & unProgramme) = delete;

//-------------------------------------------- Constructeurs - destructeur
    Programme(const Programme & unProgramme) = delete;

    Programme(Declarations* declarations, Instructions* instructions);
    ~Programme();

    // correspond aux 4 options possibles de la ligne de commande
	void afficher();
	void transformer();
	void executer();
	void analyser();

	int getValeur(std::string const& identifiant) const;
    void setValeur(std::string const& identifiant, int valeur);

//------------------------------------------------------------------ PRIVE 

protected:

private:

	Declarations* _declarations;
	Instructions* _instructions;

};

//----------------------------------------- Types dépendants de <Programme>

#endif // PROGRAMME_H

