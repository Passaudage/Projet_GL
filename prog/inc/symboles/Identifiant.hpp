#ifndef IDENTIFIANT_HPP
#define IDENTIFIANT_HPP

#include "symboles/Expression.hpp"
#include <string>
#include <unordered_set>

class Identifiant;

class Identifiant : public Expression
{
public:
//----------------------------------------------------- Méthodes publiques
	std::string const& get() const;
	virtual int calculer(Programme& programme);
	void afficher();
	Expression* optimiser(Programme& programme);
	virtual std::unordered_set<Identifiant*> getIdentifiants();
	bool estEvaluable(Programme& programme);

//-------------------------------------------- Constructeurs - destructeur
	Identifiant(std::string const& identifiant);
protected:
	std::string _identifiant;
};

#endif