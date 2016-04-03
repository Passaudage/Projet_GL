#ifndef ERREURS_HPP
#define ERREURS_HPP

#include <string>

class Symbole;

/*
 * Classe permettant de gérer les erreurs.
 * Prend en charge un message personnalisé.
 */
class ExceptionFarfadet
{
public:

	ExceptionFarfadet(std::string message);
	virtual ~ExceptionFarfadet();

	virtual std::string const& getErreur();

	static std::string declaration_const_double;
	static std::string declaration_var_double;
	static std::string division_zero;

protected:
	std::string _message;

};

/*
 * Classe permettant de gérer les erreurs relatives à un symbole.
 * Le numéro de ligne et la position du symbole dans la ligne
 * est automatique ajoutée avant le message personnalisé.
 */
class ExceptionSymbole : public ExceptionFarfadet
{
public:
	ExceptionSymbole(Symbole* symbole, std::string message);
	virtual ~ExceptionSymbole();

	virtual std::string const& getErreur();

	static std::string symbole_non_attendu;

protected:

};

#endif
