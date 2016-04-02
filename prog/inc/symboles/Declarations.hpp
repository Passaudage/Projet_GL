#ifndef DECLARATIONS_H
#define DECLARATIONS_H


#include "Symbole.hpp"

#include <string>
#include <list>
#include <unordered_set>
#include <map>


using namespace std;

class Identifiant;
class Expression;

/*
 * Gère l'ensemble des déclarations du programme, variables et constantes.
 */
class Declarations : public Symbole
{
public:
	/*
	 * Une entité correspond à la donnée d'une variable ou d'une constante.
	 * L'ensemble des informations nécessaires à sa description sont présentes
	 * dans cette structure.
	 */
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

		bool static_initialise;
		bool static_utilise;
	};

	typedef std::pair<std::string, Entite> Enregistrement;
	typedef std::pair<std::string, Identifiant*> Entree;
	typedef std::list<Enregistrement> ListEntites;

	/*
	 * Accumulateur de constantes.
	 * cf. grammaire.
	 */
	class IDC : public Symbole
	{
	public:
		IDC();

		void ajouterConstante(std::string const& identifiant, int valeur);
		ListEntites& getliste();

	private:
		ListEntites _listEntites;

	};

	/*
	 * Accumulateur de variables.
	 * cf. grammaire.
	 */
	class IDV : public Symbole
	{
	public:
		IDV();

		void ajouterVariable(std::string const& identifiant);
		ListEntites& getliste();

	private:
		ListEntites _listEntites;
	};


    Declarations& operator=(const Declarations & unDeclarations) = delete;
    Declarations(const Declarations & unDeclarations) = delete;

    Declarations();


	inline bool identifiantPris(string const& identifiant) const;
	/*
	 * Ajoute ces constantes aux déclarations déjà présentes.
	 */
	void enregistrerConstantes(IDC& idc);

	/*
	 * Ajoute ces variables aux déclarations déjà présentes.
	 */
	void enregistrerVariables(IDV& idv);

	int getValeur(string const& identifiant) const;
	void setValeur(string const& identifiant, int valeur);
	bool estModifiable(string const& identifiant);

	void afficher();

	/*
	 * Effectue l'analyse statique du programme.
	 * Les informations sont récoltées lors de l'enregistrement des
	 * instructions, via l'uilisation des méthodes Declarations::signer*().
	 */
	void analyser();

	void signerUtiliser(Expression* expression);
	void signerUtiliser(Identifiant* identifiant);
	void signerAffecter(Identifiant* identifiant);

	/*
	 * Lorsqu'une variable n'est pas déclarée mais tout de même utilisée,
	 * appeler cette méthode permet d'ajouter la déclaration de cette
	 * variable. Appelée lors de l'optimisation du programme.
	 */
	void declarerVarNonDeclarees();

	/*
	 * Enlève l'ensemble des déclarations de constantes.
	 * Appelée lors de l'optimisation du programme.
	 */
	void viderConstantes();

	/*
	 * Effectue l'intersection de l'ensemble des identifiants présents
	 * dans Declarations avec ceux passés en arguments.
	 * Appelée lors de l'optimisation du programme.
	 */
	void intersecterIdentifiants(
		std::unordered_set<std::string>& identifiants);

private:

	void formaterIdentifiants(
		std::multimap<std::string, Identifiant*>& multimap);

protected:
	map<string, Entite> _entites;

	/*
	 * Dictionnaires et ensembles nécessaires à l'analyse statique.
	 */
	std::multimap<std::string, Identifiant*> _varUtiliseesNonDeclarees;
	std::multimap<std::string, Identifiant*> _varUtiliseesNonAffectees;
	std::multimap<std::string, Identifiant*> _varAffecteesNonDeclarees;

	std::unordered_set<std::string> _varUtilisees;
	std::multimap<std::string, Identifiant*> _constModifiees;

};


#endif // DECLARATIONS_H

