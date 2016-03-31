#include "symboles/Identifiant.hpp"
#include "symboles/Valeur.hpp"

#include <iostream>


Identifiant::Identifiant(std::string const& identifiant) : Expression(IDENTIFIANT), _identifiant(identifiant)
{
}

int Identifiant::calculer(Programme& programme)
{
	return programme.getValeur(_identifiant);
}

std::string const& Identifiant::get() const
{
	return _identifiant;
}

void Identifiant::afficher()
{
	std::cout << _identifiant;
}

std::unordered_set<Identifiant*> Identifiant::getIdentifiants()
{
	std::unordered_set<Identifiant*> id;
	id.insert(this);
	return id;
}

std::pair<Expression*, Expression*> Identifiant::optimiser(Programme& programme, bool)
{
	if(!programme.estModifiable(_identifiant)){ // Si c'est une constante
		std::pair<Expression*, Expression*> retour(new Valeur(this->calculer(programme)), nullptr);
		delete this;
		return retour;
	} else {
		return std::pair<Expression*, Expression*>(this, nullptr);
	}
}

bool Identifiant::estEvaluable(Programme& programme)
{
	if(!programme.estModifiable(_identifiant)){ // Si c'est une constante
		return true;
	} else {
		return false;
	}
}
