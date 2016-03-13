#include "symboles/Valeur.hpp"

int Valeur::calculer(Programme &)
{
	return _valeur;
}

Valeur::Valeur(int valeur):Expression(VALEUR),_valeur(valeur)
{
}
