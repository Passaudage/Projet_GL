#include <string>
#include <iostream>

#include <sstream>
#include <iomanip>

#include <exception>

#include "Lexer.hpp"
#include "Symbole.hpp"

#include "symboles/SymbolesTerminaux.hpp"
#include "symboles/Valeur.hpp"
#include "symboles/Identifiant.hpp"


// #### Constructeur et destructeur #### //
Lexer::Lexer(std::string const& nomFichier)
{	
	_fichierSource.open(nomFichier);

	if(_fichierSource.good()) {

	} else {
		/* TODO : faire mieux comme message et gestion des erreurs */
		throw "Bouh, tu es nul, ce n'est pas le bon fichier lutin !";
	}

	_delimiteurSuivant = nullptr;

	_symboleSuivant = lire_decaler();
	decaler();
}

Lexer::~Lexer()
{
	_fichierSource.close();
}

/*
// #### Surcharge #### //
std::ostream& operator << (std::ostream& os, const Lexer& lex)  
{
    return os;  
} 
*/

// #### Publique #### //

Symbole* Lexer::lireSymboleCourant()
{
	return _symboleCourant;
}

Symbole* Lexer::lireSymboleSuivant()
{
	return _symboleSuivant;
}

bool Lexer::decaler()
{
	_symboleCourant = _symboleSuivant;
	
	if(_symboleCourant == nullptr)
		return false;

	if(_delimiteurSuivant != nullptr) {
		_symboleSuivant = _delimiteurSuivant;
		_delimiteurSuivant = nullptr;
	} else {
		_symboleSuivant = lire_decaler();
	}

	return true;
}

// #### Privée #### //

Symbole* Lexer::lire_decaler()
{
	Symbole* symbole = nullptr;
	char caractere;
	bool debut_mot = false;

	std::stringstream sstr;

	for(;;) {

		// lecture du prochain caractère
		if(!_fichierSource.get(caractere)) {
			//fin du flux

			symbole = new FinDeFlux();

			if(!debut_mot) {
				// on renvoie la fin de flux
				return symbole;
			}
			// il reste à transformer en symbole
			// ce qui est dans le "buffer"
			break;
		}

		//std::cout << "-->" << caractere << "<--" << std::endl;

		// est-ce un delimiteur ?

		if(caractere == ' ' || caractere == '\n' || caractere == '\r') {
			if(!debut_mot) {
				// on regarde le prochain caractère
				continue;
			}

			// délimiteur => fin du symbole courant
			//
			// il reste à transformer en symbole
			// ce qui est dans le "buffer"
			break;
		}

		symbole = lire_delimiteur(caractere);

		if(symbole != nullptr) {
			// on a trouvé un délimiteur,
			//
			// il reste à transformer en symbole
			// ce qui est dans le "buffer"
			break;
		}

		sstr << caractere;

		debut_mot = true;
	}

	std::string identifiant;
	sstr >> identifiant;

	if(!identifiant.empty()) {
		Symbole* delimiteur = symbole;

		// créer le symbole correspondant à l'identifiant

		symbole = lire_identifiant(identifiant);

		if(delimiteur != nullptr) {
			// si un délimiteur a été trouvé précédemment
			// on le met de côté pour un prochain décalage
			// car il correspond au symbole après le suivant
			_delimiteurSuivant = delimiteur;
		}

		return symbole;
		
	} else if(symbole != nullptr) {
		// on renvoie le délimiteur seulement
		// car pas d'identifiant/mot clé trouvé avant
		return symbole;
	}

	return nullptr;
}

Symbole* Lexer::lire_delimiteur(char& caractere)
{
	Symbole* delimiteur = nullptr;
	char caractere_suivant;

	switch(caractere) {
		case ',':
			delimiteur = new Virgule();
			break;
		case ';':
			delimiteur = new PointVirgule();
			break;

		case '(':
			delimiteur = new ParentheseOuvrante();
			break;
		case ')':
			delimiteur = new ParentheseFermante();
			break;

		case '+':
			delimiteur = new OperateurAdd(true);
			break;
		case '-':
			delimiteur = new OperateurAdd(false);
			break;

		case '*':
			delimiteur = new OperateurMult(true);
			break;
		case '/':
			delimiteur = new OperateurMult(false);
			break;

		case '=':
			delimiteur = new Egal();
			break;

		case ':':

			if(!_fichierSource.get(caractere_suivant) ||
				caractere_suivant != '=') { 
				throw "Symbole \":\" invalide";
			}

			delimiteur = new Affectation();
			
			break;
	}

	return delimiteur;
}


Symbole* Lexer::lire_identifiant(std::string& identifiant)
{
	// est-ce un mot clé ?

	if(identifiant == "const") {
		return new Constante();
	} else if (identifiant == "var") {
		return new Variable();
	} else if(identifiant == "lire") {
		return new Lecture();
	} else if(identifiant == "ecrire") {
		return new Affichage();
	}

	// est-ce une valeur entière ?

	bool valeur = true;

	for(std::string::iterator it = identifiant.begin();
		it != identifiant.end(); ++it) {
		if(!std::isdigit(*it)) {
			valeur = false;
			break;
		}
	}

	if(valeur) {
		return new Valeur(std::stoi(identifiant));
	}

	// est-ce un identifiant correct ?

	char premier = *identifiant.begin();

	if(std::isalpha(premier) || premier == '_') {
		// ok

		// TODO : vérifier qu'il ne contient pas des caractères interdits

		return new Identifiant(identifiant);
	}

	return nullptr;
}

std::string const& Lexer::getCode()
{
	// TODO : lire le fichier pour renvoyer le code de départ
	// attention : le curseur courant doit être sauvegardé

	std::string* code = new std::string("CODE");

	return *code;
}