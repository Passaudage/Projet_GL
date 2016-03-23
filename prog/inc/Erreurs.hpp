#ifndef ERREURS_HPP
#define ERREURS_HPP

#include <string>

class Symbole;

class ExceptionFarfadet
{
public:

	ExceptionFarfadet(std::string message);
	virtual ~ExceptionFarfadet();

	virtual std::string const& getErreur();

protected:
	std::string _message;

};

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
