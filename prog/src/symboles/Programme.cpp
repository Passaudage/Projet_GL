#include "symboles/Programme.hpp"

#include "symboles/Declarations.hpp"
#include "symboles/Instructions.hpp"

#include "symboles/Identifiant.hpp"

#include <unordered_set>
#include <unordered_map>
#include <string>
#include <iostream>

Programme::Programme(Declarations* declarations, Instructions* instructions) : 
	Symbole(PROGRAMME),
	_declarations(declarations),
	_instructions(instructions)
{
}

Programme::~Programme()
{
	delete _declarations;
	delete _instructions;
}

void Programme::afficher()
{
	_declarations->afficher();
	_instructions->afficher();
}

void Programme::transformer()
{
	// TODO :
	// propager les constantes
	// éliminer les opérations avec élément neutre
	// éliminer les parenthèses inutiles ?

	// 0*x ; x*0 ; x/1 ; x+0 ; 0+x
	// ERREUR : x/0

	// plusieurs affectations de suite pour une même variable
	// a:=5;lire b;a:=7; ---> lire b;a:=7;
	// a:=8;b:=7;lire a; ---> b:=7;lire a;
	
	_instructions->optimiser(*this);
}

void Programme::executer()
{
	_instructions->executer(*this);
}

void Programme::analyser()
{
	// TODO :

	// Instructions
	// variable utilisée sans avoir été déclarée
	// variable utilisée sans avoir été affectée
	// variable déclarée jamais utilisée
	// constante modifiée

	// Declarations
	// variables/constantes déclarées avec le même identifiant
	// => d'ailleurs, que faire dans le mode d'exécution normal ?
	_declarations->analyser();
}

int Programme::getValeur(std::string const& identifiant) const
{
	return _declarations->getValeur(identifiant);
}

void Programme::setValeur(std::string const& identifiant, int valeur)
{
	_declarations->setValeur(identifiant, valeur);
}

bool Programme::estModifiable(std::string const& identifiant)
{
	return _declarations->estModifiable(identifiant);
}
