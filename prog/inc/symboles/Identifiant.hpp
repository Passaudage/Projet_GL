#include "symboles/Expression.hpp"
#include <string>

class Identifiant : public Expression
{
public:
//----------------------------------------------------- Méthodes publiques
	std::string const& get() const;
	virtual int calculer(Programme& programme);

//-------------------------------------------- Constructeurs - destructeur
	Identifiant(std::string const& identifiant);
protected:
	std::string const& _identifiant;
};