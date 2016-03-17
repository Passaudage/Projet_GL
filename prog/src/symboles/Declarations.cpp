#include "symboles/Declarations.hpp"
bool Declarations::identifiantPris(string& identifiant)
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

int Declarations::getValeur(string& identifiant)
{
	if(!identifiantPris(identifiant))
		return 0;
	return _entites.find(identifiant)->second.valeur;
}

void Declarations::setValeur(string& identifiant, int valeur) {
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

	Enregistrement enrVariable(identifiant, entite);

	_listEntites.push_front(enrVariable);
}
