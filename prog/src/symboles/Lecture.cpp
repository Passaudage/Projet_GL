#include "symboles/Lecture.hpp"
#include <iostream>

const std::string Lecture::_keyword = "lire";

void Lecture::afficher()
{
	std::cout << _keyword << ' ' << _identifiant.get() << ';' << std::endl;
}

void Lecture::effectuer(Programme & programme)
{
	int valeur;	
	std::cin >> valeur;
	programme.setValeur(_identifiant.get(), valeur);
}

Lecture::Lecture(Identifiant& identifiant):_identifiant(identifiant)
{
}

Lecture::~Lecture()
{
	delete &_identifiant;
}
