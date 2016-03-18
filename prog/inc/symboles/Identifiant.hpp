#ifndef IDENTIFIANT_HPP
#define IDENTIFIANT_HPP

#include "symboles/Expression.hpp"
#include <string>

class Identifiant : public Expression
{
public:
//----------------------------------------------------- Méthodes publiques
	std::string const& get() const;
	virtual int calculer(Programme& programme);
	void afficher();

//-------------------------------------------- Constructeurs - destructeur
	Identifiant(std::string const& identifiant);
protected:
	std::string const& _identifiant;
};

#endif