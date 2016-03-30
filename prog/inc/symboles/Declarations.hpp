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
#include <unordered_set>
#include <map>

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
using namespace std;

class Identifiant;
class Expression;

class Declarations : public Symbole
{
//----------------------------------------------------------------- PUBLIC

public:
//------------------------------------------------------ Classes publiques
	struct Entite {
		enum Type {
			CONST, VAR
		};

		Entite(Type type);

		void resetFlags();

		int valeur;

		bool const modifiable;
		bool initialise;
		bool utilise;
	};

	typedef std::pair<std::string, Entite> Enregistrement;
	typedef std::pair<std::string, Identifiant*> Entree;
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
	bool estModifiable(string const& identifiant);

	void afficher();

	void analyser();

	void signerUtiliser(Expression* expression);
	void signerUtiliser(Identifiant* identifiant);
	void signerAffecter(Identifiant* identifiant);

	void viderConstantes();

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

	void formaterIdentifiants(
		std::multimap<std::string, Identifiant*>& multimap);

protected:
//----------------------------------------------------- Attributs protégés
	unordered_map<string, Entite> _entites;

	std::multimap<std::string, Identifiant*> _varUtiliseesNonDeclarees;
	std::multimap<std::string, Identifiant*> _varUtiliseesNonAffectees;
	std::multimap<std::string, Identifiant*> _varAffecteesNonDeclarees;

	std::unordered_set<std::string> _varUtilisees;
	std::multimap<std::string, Identifiant*> _constModifiees;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Declarations>

#endif // DECLARATIONS_H

