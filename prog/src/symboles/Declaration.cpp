#include "symboles/Declarations.hpp"


Declarations::IDC::IDC() : Symbole(Symbole::Type::DECLARATION_CON)
{
}

Declarations::IDC::~IDC()
{
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

Declarations::IDV::~IDV()
{
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
