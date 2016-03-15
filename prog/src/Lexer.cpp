#include <string>
#include <iostream>

#include <sstream>
#include <iomanip>

#include <exception>

#include "Lexer.hpp"
#include "Symbole.hpp"

#include "symboles/SymbolesTerminaux.hpp"
#include "symboles/Valeur.hpp"

// #### Constructeur et destructeur #### //
Lexer::Lexer(std::string & nomFichier)
{	
	_fichierSource.open(nomFichier);

	if(_fichierSource.good()) {

	} else {
		/* TODO : faire mieux comme message et gestion des erreurs */
		throw std::exception();
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
			std::cerr << "Plus rien à lire" << std::endl;
			return nullptr;
		}

		//std::cout << "-->" << caractere << "<--" << std::endl;

		// est-ce un delimiteur ?

		if(caractere == ' ' || caractere == '\n' || caractere == '\r') {
			if(debut_mot) {
				break;
			} else {
				continue;
			}
		}

		try {
			symbole = lire_delimiteur(caractere);
		} catch(std::exception& e) {
			std::cerr << "Erreur de lecture de symbole" << std::endl;
		}

		if(symbole != nullptr) {
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
			// si un délimiteur a été trouvé
			// on le met de côté pour un prochain décalage
			_delimiteurSuivant = delimiteur;
		}

		return symbole;
		
	} else if(symbole != nullptr) {
		return symbole;
	}

	std::cout << "identifiant : " << identifiant << std::endl;

	return nullptr;
}

Symbole* Lexer::lire_delimiteur(char& caractere)
{
	Symbole* delimiteur = nullptr;
	char caractere_suivant;

	switch(caractere) {
		case ',':
			std::cout << "Virgule !" << std::endl;
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

			if(!_fichierSource.get(caractere_suivant)) {
				std::cerr << "Plus rien à lire" << std::endl;
				throw;
			} else if(caractere_suivant != '=') {
				std::cerr << "Symbole \":\" invalide" << std::endl;
				throw;
			}

			//std::cout << "caractere_suivant >" << caractere_suivant << "<" << std::endl;

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
 