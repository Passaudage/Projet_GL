#include "symboles/Declarations.hpp"

#include <iostream>

#include "symboles/Identifiant.hpp"
#include "symboles/Expression.hpp"
#include "Erreurs.hpp"

Declarations::Entite::Entite(Declarations::Entite::Type type) :
	modifiable((type == CONST) ? false : true)
{
	valeur = 0;
	utilise = false;
	static_utilise = false;
	optim_sale = false;

	if(type == CONST) {
		initialise = true;
		static_initialise = true;
	} else {
		initialise = false;
		static_initialise = false;
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
		{
			delete &idc;
			throw ExceptionFarfadet(ExceptionFarfadet::declaration_const_double);
		}
		_entites.insert(*it);	
	}
}

void Declarations::enregistrerVariables(IDV& idv)
{
	Declarations::ListEntites::iterator it;
	Declarations::ListEntites& liste = idv.getliste();
	for (it = liste.begin() ; it != liste.end() ; it++) {
		if (identifiantPris(it->first))
		{
			delete &idv;
			throw ExceptionFarfadet(ExceptionFarfadet::declaration_var_double);
		}
		_entites.insert(*it);	
	}
}

int Declarations::getValeur(string const& identifiant) const
{
	if(!identifiantPris(identifiant))
		return 0;
	return _entites.find(identifiant)->second.valeur;
}

bool Declarations::estModifiable(string const& identifiant)
{
	if(!identifiantPris(identifiant))
		return true;
	return _entites.find(identifiant)->second.modifiable;
}

bool Declarations::estSale(string const& identifiant)
{
	if(!identifiantPris(identifiant))
		return false;
	return _entites.find(identifiant)->second.optim_sale;	
}

void Declarations::rendSale(string const& identifiant)
{
	if(!identifiantPris(identifiant)) {
		Entite entite(Entite::Type::VAR);
		entite.optim_sale = true;
		_entites.insert(Enregistrement(identifiant, entite));
	} else {
		_entites.find(identifiant)->second.optim_sale = true;
	}
}

void Declarations::rendPropre(string const& identifiant)
{
	if(identifiantPris(identifiant)) {
		_entites.find(identifiant)->second.optim_sale = false;
	} 
}

void Declarations::setValeur(string const& identifiant, int valeur) {
	if (identifiantPris(identifiant)) {
		map<string, Entite>::iterator it = _entites.find(identifiant);
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
	map<string, Entite>::iterator it; 
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
	std::map<string, Entite>::iterator it;

	it = _entites.find(identifiant->get());

	// est-ce que la variable a déjà été déclarée ?
	
	if(it == _entites.end()) {
		// pas encore declarée
		_varUtiliseesNonDeclarees.insert(Entree(identifiant->get(), identifiant));
	} else {
		// déclarée
		it->second.static_utilise = true;

		// est-elle initialisée ?

		if(!it->second.static_initialise) {
			_varUtiliseesNonAffectees.insert(Entree(identifiant->get(), identifiant));
		}
	}

	_varUtilisees.insert(identifiant->get());
}

void Declarations::signerAffecter(Identifiant* identifiant)
{
	map<string, Entite>::iterator it;

	it = _entites.find(identifiant->get());

	if(it == _entites.end()) {
		// variable affectée mais non déclarée
		_varAffecteesNonDeclarees.insert(Entree(identifiant->get(), identifiant));
	} else {
		it->second.static_utilise = true;
		it->second.static_initialise = true;

		if(!it->second.modifiable) {
			_constModifiees.insert(Entree(identifiant->get(), identifiant));
		}
	}
}

void Declarations::intersecterIdentifiants(
	std::unordered_set<std::string>& identifiants)
{
	std::unordered_set<std::string> aDetruire;

	for(std::pair<std::string, Entite> paire : _entites) {
		std::unordered_set<std::string>::iterator itId =
			identifiants.find(paire.first);

			if(itId == identifiants.end())
				aDetruire.insert(paire.first);
	}

	for(std::string identifiant : aDetruire) {
		_entites.erase(identifiant);
	}
}

void Declarations::declarerVarNonDeclarees()
{
	std::unordered_set<std::string> varNonDeclarees;

	for(Entree entree : _varUtiliseesNonDeclarees) {
		varNonDeclarees.insert(entree.first);
	}

	for(Entree entree : _varAffecteesNonDeclarees) {
		varNonDeclarees.insert(entree.first);
	}

	for(std::string variable : varNonDeclarees) {
		Entite entite(Entite::Type::VAR);

		_entites.insert(Enregistrement(variable, entite));
	}

}

void Declarations::analyser()
{
	// faire l'affichage correct en lisant les données précalculées

	//std::cout << "Analyse statique du code lutin :" << std::endl;

	if(!_varUtiliseesNonDeclarees.empty()) {
		std::cerr << "Identifiants utilisés non déclarés :" << std::endl;
		formaterIdentifiants(_varUtiliseesNonDeclarees);
	}

	if(!_varAffecteesNonDeclarees.empty()) {
		std::cerr << "Identifiants affectés non déclarés :" << std::endl;
		formaterIdentifiants(_varAffecteesNonDeclarees);
	}

	if(!_varUtiliseesNonAffectees.empty()) {
		std::cerr << "Identifiants utilisés non initialisés :" << std::endl;
		formaterIdentifiants(_varUtiliseesNonAffectees);
	}

	if(_entites.size() > _varUtilisees.size()) {
		std::cerr << "Identifiants déclarés mais inutilisés :" << std::endl;
		std::unordered_set<std::string>::iterator it;

		for(std::pair<std::string, Entite> pairEntite : _entites) {
			it = _varUtilisees.find(pairEntite.first);

			if(it == _varUtilisees.end()) {
				std::cerr << "   " << pairEntite.first << std::endl;
			}
		}
	}

	if(!_constModifiees.empty()) {
		std::cerr << "Modifications de constantes : " << std::endl;
		formaterIdentifiants(_constModifiees);
	}
}

void Declarations::formaterIdentifiants(
	std::multimap<std::string, Identifiant*>& multimap)
{
	bool premier = true; // Est-ce vraiment utile ?
	std::string keyBuffer;

	for(std::pair<std::string, Identifiant*> pairIdentifiant : multimap) {
		if(keyBuffer != pairIdentifiant.first) {
			keyBuffer = pairIdentifiant.first;

			if(!premier) {
				std::cerr << std::endl;
			}
			std::cerr << "   " << keyBuffer << " : ";
		}

		std::cerr << "l." << pairIdentifiant.second->getLigne() << " ";

		premier = false;
	}

	std::cerr << std::endl;
}

void Declarations::viderConstantes()
{
	std::unordered_set<std::string> aDetruire;

	for(std::pair<std::string, Entite> paire : _entites) {
		if(!paire.second.modifiable)
			aDetruire.insert(paire.first);
	}

	for(std::string id : aDetruire) {
		_entites.erase(id);
	}
}
