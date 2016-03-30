#include "symboles/Valeur.hpp"

#include <iostream>
#include "symboles/Identifiant.hpp"

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

std::unordered_set<Identifiant*> Valeur::getIdentifiants()
{
	std::unordered_set<Identifiant*> id;
	return id;
}

void Valeur::afficher()
{
	std::cout << _valeur;
}

std::pair<Expression*, Expression*> Valeur::optimiser(Programme&, bool)
{
	std::cout << "On optimise :" << _valeur << std::endl;
	return std::pair<Expression*, Expression*>(this, nullptr);
}

bool Valeur::estEvaluable(Programme&)
{
	return true;
}