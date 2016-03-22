#include "symboles/Declarations.hpp"

#include <iostream>

#include "symboles/Identifiant.hpp"
#include "symboles/Expression.hpp"

Declarations::Entite::Entite(Declarations::Entite::Type type) :
	modifiable((type == CONST) ? false : true)
{
	valeur = 0;
	utilise = false;

	if(type == CONST) {
		//modifiable = false;
		initialise = true;
		
	} else {
		//modifiable = true;
		initialise = false;
	}
}

void Declarations::Entite::resetFlags()
{
	utilise = false;
	initialise =  modifiable ? false : true;
}

bool Declarations::identifiantPris(string const& identifiant) const
{
	return _entites.count(identifiant) != 0;
}

void Declarations::enregistrerConstantes(IDC& idc)
{
	Declarations::ListEntites::iterator it;
	Declarations::ListEntites& liste = idc.getliste();
	for (it = liste.begin() ; it != liste.end() ; it++) {
		if (identifiantPris(it->first))
			throw "Déclaration d'une constante dont l'identifiant est déjà pris !!!";
		_entites.insert(*it);	
	}
}

void Declarations::enregistrerVariables(IDV& idv)
{
	Declarations::ListEntites::iterator it;
	Declarations::ListEntites& liste = idv.getliste();
	for (it = liste.begin() ; it != liste.end() ; it++) {
		if (identifiantPris(it->first))
			throw "Déclaration d'une variable dont l'identifiant est déjà pris !!!";
		_entites.insert(*it);	
	}
}

int Declarations::getValeur(string const& identifiant) const
{
	if(!identifiantPris(identifiant))
		return 0;
	return _entites.find(identifiant)->second.valeur;
}

void Declarations::setValeur(string const& identifiant, int valeur) {
	if (identifiantPris(identifiant)) {
		unordered_map<string, Entite>::iterator it = _entites.find(identifiant);
		Entite& entite = it->second;
		if (entite.modifiable) 
			entite.valeur = valeur; 
		else
			throw "Tentative de modification d'une valeur déclarée constante !";
	} else {
		Entite entite(Entite::Type::VAR);
		entite.valeur = valeur;
		entite.initialise = true;

		_entites.insert(Enregistrement(identifiant, entite));
	}
}

Declarations::Declarations():Symbole(Symbole::Type::DECLARATIONS)
{
}

//----------------------------------------------------------------- IDC/V Stuff
Declarations::IDC::IDC() : Symbole(Symbole::Type::DECLARATION_CON)
{
}

Declarations::ListEntites& Declarations::IDC::getliste()
{
	return _listEntites;
}

void Declarations::IDC::ajouterConstante(std::string const& identifiant, int valeur)
{
	Entite entite(Entite::Type::CONST);

	entite.valeur = valeur;

	Enregistrement enrConstante(identifiant, entite);

	_listEntites.push_front(enrConstante);
}

Declarations::IDV::IDV() : Symbole(Symbole::Type::DECLARATION_VAR)
{
}

Declarations::ListEntites& Declarations::IDV::getliste()
{
	return _listEntites;
}

void Declarations::IDV::ajouterVariable(std::string const& identifiant)
{
	Entite entite(Entite::Type::VAR);

	Enregistrement enrVariable(identifiant, entite);

	_listEntites.push_front(enrVariable);
}

void Declarations::afficher()
{
	unordered_map<string, Entite>::iterator it; 
	for(it = _entites.begin(); it != _entites.end(); it++)
	{
		string temp = "";
		Entite e = it->second;
		if(e.modifiable == true){
			temp += "var ";
			temp += it->first;
			temp += ";";
		} else{
			temp += "const ";
			temp += it->first;
			temp += "=";
			temp += std::to_string(e.valeur);
			temp += ";";
		}
		std::cout << temp << std::endl;
	}
}

void Declarations::signerUtiliser(Expression* expression)
{
	std::unordered_set<Identifiant*> setId = expression->getIdentifiants();
	
	for(Identifiant* identifiant : setId) {
		signerUtiliser(identifiant);
	}
}

void Declarations::signerUtiliser(Identifiant* identifiant)
{
	//std::cout << "signer utiliser (" << identifiant->get() << ")" << std::endl;
	unordered_map<string, Entite>::iterator it;

	it = _entites.find(identifiant->get());

	// est-ce que la variable a déjà été déclarée ?
	
	if(it == _entites.end()) {
		// pas encore declarée
		_varUtiliseesNonDeclarees.insert(Entree(identifiant->get(), identifiant));
	//	std::cout << " -> pas encore déclarée !" << std::endl;
	} else {
		// déclarée
		it->second.utilise = true;
	//	std::cout << " -> déclarée !" << std::endl;

		// est-elle initialisée ?

		if(!it->second.initialise) {
	//		std::cout << " -> déclarée mais non initialisée !" << std::endl;
			_varUtiliseesNonAffectees.insert(Entree(identifiant->get(), identifiant));
		}
	}

	_varUtilisees.insert(identifiant->get());
}

void Declarations::signerAffecter(Identifiant* identifiant)
{
	//std::cout << "signer affecter" << std::endl;
	unordered_map<string, Entite>::iterator it;

	it = _entites.find(identifiant->get());

	if(it == _entites.end()) {
		// variable affectée mais non déclarée
		_varAffecteesNonDeclarees.insert(Entree(identifiant->get(), identifiant));
	//	std::cout << " -> affectée mais non déclarée !" << std::endl;
	} else {
		if(!it->second.modifiable) {
			_constModifiees.insert(Entree(identifiant->get(), identifiant));
	//		std::cout << " -> constante modifiée !" << std::endl;
		}
	}
}

void Declarations::analyser()
{
	// faire l'affichage correct en lisant les données précalculées

	std::cout << "Analyse statique du code lutin :" << std::endl;

	if(!_varUtiliseesNonDeclarees.empty()) {
		std::cout << "Identifiants utilisés non déclarés :" << std::endl;
		formatterIdentifiants(_varUtiliseesNonDeclarees);
	}

	if(!_varAffecteesNonDeclarees.empty()) {
		std::cout << "Identifiants affectés non déclarés :" << std::endl;
		formatterIdentifiants(_varAffecteesNonDeclarees);
	}

	if(!_varUtiliseesNonAffectees.empty()) {
		std::cout << "Identifiants utilisés non initialisés :" << std::endl;
		formatterIdentifiants(_varUtiliseesNonAffectees);
	}

	if(_entites.size() > _varUtilisees.size()) {
		std::cout << "Identifiants déclarés mais inutilisés :" << std::endl;
		std::unordered_set<std::string>::iterator it;

		for(std::pair<std::string, Entite> pairEntite : _entites) {
			it = _varUtilisees.find(pairEntite.first);

			if(it == _varUtilisees.end()) {
				std::cout << "   " << pairEntite.first << std::endl;
			}
		}
	}

	if(!_constModifiees.empty()) {
		std::cout << "Modifications de constantes : " << std::endl;
		formatterIdentifiants(_constModifiees);
	}
}

void Declarations::formatterIdentifiants(
	std::multimap<std::string, Identifiant*>& multimap)
{
	bool premier = true; // Est-ce vraiment utile ?
	std::string keyBuffer;

	for(std::pair<std::string, Identifiant*> pairIdentifiant : multimap) {
		if(keyBuffer != pairIdentifiant.first) {
			keyBuffer = pairIdentifiant.first;

			if(!premier) {
				std::cout << std::endl;
			}
			std::cout << "   " << keyBuffer << " ";
		}

		std::cout << "l.x ";

		premier = false;
	}

	std::cout << std::endl;
}