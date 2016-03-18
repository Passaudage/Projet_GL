#include "symboles/Valeur.hpp"

#include <iostream>


int Valeur::calculer(Programme &)
{
	return _valeur;
}

int Valeur::getValeur() const
{
	return _valeur;
}

Valeur::Valeur(int valeur):Expression(VALEUR),_valeur(valeur)
{
}

void Valeur::afficher()
{
	std::cout << _valeur;
}