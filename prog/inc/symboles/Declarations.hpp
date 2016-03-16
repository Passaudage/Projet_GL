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

#include <string>
#include <list>
#include <unordered_map>

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
using namespace std;

class Declarations : public Symbole
{
//----------------------------------------------------------------- PUBLIC

public:
//------------------------------------------------------ Classes publiques
	struct Entite {
		int _valeur;
		bool _initialise;
		bool _modifiable;
	};

	typedef std::pair<std::string, Entite> Enregistrement; 
	typedef std::list<std::pair<std::string, Entite>> ListEntites;

	class IDC : public Symbole
	{
	public:
		IDC();
		~IDC();

		void ajouterConstante(std::string const& identifiant, int valeur);

	private:
		ListEntites _listEntites;

	};

	class IDV : public Symbole
	{
	public:
		IDV();
		~IDV();

		void ajouterVariable(std::string const& identifiant);

	private:
		ListEntites _listEntites;
	};

//----------------------------------------------------- Méthodes publiques
	void enregistrerConstantes(IDC& idc);
	void enregistrerVariables(IDV& idv);




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
	unordered_map<string, Entite> _entites;	

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Declarations>

#endif // DECLARATIONS_H

