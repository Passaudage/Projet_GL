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
	virtual std::unordered_set<Identifiant*> getIdentifiants();

//-------------------------------------------- Constructeurs - destructeur
	Identifiant(std::string const& identifiant);
protected:
	std::string _identifiant;
};

#endif