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
		int valeur;
		bool initialise;
		bool modifiable;
	};

	typedef std::pair<std::string, Entite> Enregistrement; 
	typedef std::list<Enregistrement> ListEntites;

	class IDC : public Symbole
	{
	public:
		IDC();

		void ajouterConstante(std::string const& identifiant, int valeur);
		ListEntites& getliste();

	private:
		ListEntites _listEntites;

	};

	class IDV : public Symbole
	{
	public:
		IDV();

		void ajouterVariable(std::string const& identifiant);
		ListEntites& getliste();

	private:
		ListEntites _listEntites;
	};

//----------------------------------------------------- Méthodes publiques
	inline bool identifiantPris(string const& identifiant) const;
	void enregistrerConstantes(IDC& idc);
	void enregistrerVariables(IDV& idv);
	int getValeur(string const& identifiant) const;
	void setValeur(string const& identifiant, int valeur);
	void afficher();

//------------------------------------------------- Surcharge d'opérateurs
    Declarations& operator=(const Declarations & unDeclarations) = delete;

//-------------------------------------------- Constructeurs - destructeur
    Declarations(const Declarations & unDeclarations) = delete;

    Declarations();

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

