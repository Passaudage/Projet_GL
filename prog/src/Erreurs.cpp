#include "Erreurs.hpp"

#include "Symbole.hpp"

std::string ExceptionSymbole::symbole_non_attendu = "symbole non attendu par la grammaire";

std::string ExceptionFarfadet::declaration_const_double = "Déclaration d'une constante dont l'identifiant est déjà pris !!!";
std::string ExceptionFarfadet::declaration_var_double = "Déclaration d'une variable dont l'identifiant est déjà pris !!!";

std::string ExceptionFarfadet::division_zero = "Division par zéro";

ExceptionFarfadet::ExceptionFarfadet(std::string message) :
	_message(message)
{

}

ExceptionFarfadet::~ExceptionFarfadet()
{
}

std::string const& ExceptionFarfadet::getErreur()
{
	return _message;
}

ExceptionSymbole::ExceptionSymbole(Symbole* symbole, std::string message) :
	ExceptionFarfadet(message)
{
	std::string prefixe;

	prefixe = "l." + std::to_string(symbole->getLigne()) + ", c." +
		std::to_string(symbole->getCaractere());

	_message = prefixe + " : " + _message;
}

ExceptionSymbole::~ExceptionSymbole()
{}

std::string const& ExceptionSymbole::getErreur()
{
	return _message;
}
