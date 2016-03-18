#include "symboles/Lecture.hpp"
#include <iostream>

Lecture::_keyword = "lire";

void Lecture::affiche()
{
	std::cout << _keyword << ' ' << _identifiant.get() << ';';
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
