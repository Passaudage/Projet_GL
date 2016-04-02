#include "symboles/Lecture.hpp"
#include <iostream>
#include <sstream>

#include <unordered_set>

const std::string Lecture::_keyword = "lire";

void Lecture::afficher()
{
	std::cout << _keyword << ' ' << _identifiant.get() << ';' << std::endl;
}

void Lecture::effectuer(Programme & programme)
{
	std::cout << "Saisir la valeur de " << _identifiant.get() << " : ";
	int value;
	while (std::cin) {
		std::string saisie;
		std::getline(std::cin, saisie);
		std::stringstream flux(saisie);
		
		if(!(flux >> value)) {
			std::cout << "Veuillez saisir une valeur entière pour " <<
				_identifiant.get() << " : ";
			continue;
		}

		programme.setValeur(_identifiant.get(), value);
		return;
	}

	throw "Valeur à saisir manquante";
}


Lecture::Lecture(Identifiant& identifiant):_identifiant(identifiant)
{
}

void Lecture::optimiser(Programme& programme)
{
	programme.rendSale(_identifiant.get());	
}

Lecture::~Lecture()
{
	delete &_identifiant;
}

std::unordered_set<Identifiant*> const Lecture::getVarUtilisees()
{
	return std::unordered_set<Identifiant*>();
}

Identifiant const * Lecture::getVarAffectees()
{
	return &_identifiant;
}
