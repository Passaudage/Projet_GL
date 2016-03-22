#include "symboles/Declarations.hpp"

#include <iostream>

#include "symboles/Identifiant.hpp"
#include "symboles/Expression.hpp"

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
		Entite entite;
		entite.valeur = valeur;
		entite.initialise = true;
		entite.modifiable = true;
		entite.utilise = false;
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
	Entite entite;

	entite.valeur = valeur;
	entite.initialise = true;
	entite.modifiable = false;
	entite.utilise = false;

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
	Entite entite;

	entite.valeur = 0;
	entite.initialise = false;
	entite.modifiable = true;
	entite.utilise = false;

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
		//signerUtiliser(identifiant);
		std::cout << "blabla" << std::endl;
	}
	std::cout << "taille entite : " << _entites.size() << std::endl;
}

void Declarations::signerUtiliser(Identifiant* identifiant)
{
	return;
	std::cout << "signer utiliser (" << identifiant->get() << ")" << std::endl;
	unordered_map<string, Entite>::iterator it;

	//unordered_map<string, Entite> map_test = _entites;
	unordered_map<string, Entite>::iterator it2;

	it2 = _entites.find(identifiant->get());

	//it = _entites.find(identifiant->get());

	return;
	// est-ce que la variable a déjà été déclarée ?
	if(it == _entites.end()) {
		// pas encore declarée
		//varUtiliseesNonDeclarees.insert(identifiant);
		std::cout << " -> pas encore déclarée !" << std::endl;
	} else {
		// déclarée
		//(*it).second.utilise = true;
	}
	std::cout << "la fin" << std::endl;

}

void Declarations::signerAffecter(Identifiant* identifiant)
{
	std::cout << "signer affecter" << std::endl;
}

void Declarations::analyser()
{
	std::cout << "taille entite : " << std::endl;
	// faire l'affichage correct en lisant les données précalculées
}