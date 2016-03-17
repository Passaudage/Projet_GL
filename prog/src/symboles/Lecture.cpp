#include "symboles/Lecture.cpp"
#include <iostream>

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
