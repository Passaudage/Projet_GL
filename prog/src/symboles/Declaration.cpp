#include "symboles/Declarations.hpp"


Declarations::IDC::IDC() : Symbole(Symbole::Type::DECLARATION_CON)
{
}

Declarations::IDC::~IDC()
{
}

void Declarations::IDC::ajouterConstante(std::string const& identifiant, int valeur)
{
	
}

Declarations::IDV::IDV() : Symbole(Symbole::Type::DECLARATION_VAR)
{
}

Declarations::IDV::~IDV()
{
}

void Declarations::IDV::ajouterVariable(std::string const& identifiant)
{

}
