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

	_nombre_negatif = false;
	//_delimiteurSuivant = nullptr;

	Symbole* symbole = lire_decaler();

	if(symbole != nullptr)
		_fileSymboles.push(symbole);
	
	if(_fileSymboles.empty())
		throw "Le flux est vide";
	
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
	return _fileSymboles.front();
}

bool Lexer::decaler()
{
	if(_fileSymboles.empty()) 
		return false;

	_symboleCourant = _fileSymboles.front();
	_fileSymboles.pop();
	
	if(_fileSymboles.empty()) {
		Symbole* symbole = lire_decaler();

		if(symbole != nullptr)
			_fileSymboles.push(symbole);
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

	if(_nombre_negatif) {
		identifiant = identifiant.substr(1);
	}

	if(!identifiant.empty()) {
		Symbole* delimiteur = symbole;

		// créer le symbole correspondant à l'identifiant

		symbole = lire_identifiant(identifiant);

		if(symbole != nullptr)
			_fileSymboles.push(symbole);

		if(delimiteur != nullptr) {
			// si un délimiteur a été trouvé précédemment
			// on le met de côté pour un prochain décalage
			// car il correspond au symbole après le suivant
			_fileSymboles.push(delimiteur);
		}

		return nullptr;
		
	} else if(symbole != nullptr) {
		// on renvoie le délimiteur seulement
		// car pas d'identifiant/mot clé trouvé avant

		if(_nombre_negatif) {
			// on rajoute le moins que l'on avait mis en attente
			_fileSymboles.push(new OperateurAdd(false));
			_nombre_negatif = false;
		}

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
			if(_fichierSource.get(caractere_suivant) &&
				std::isdigit(caractere_suivant))
			{
				_fichierSource.unget();
				_nombre_negatif = true;
				break;
			}

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
	// est-ce une valeur entière ?

	bool valeur = true;
#ifdef MAP
	std::cout << " ------ >" << identifiant << "<----" << std::endl;
#endif
	for(std::string::iterator it = identifiant.begin();
		it != identifiant.end(); ++it) {
		if(!std::isdigit(*it)) {
			valeur = false;
			break;
		}
	}

	if(valeur) {

		int valeur_id = std::stoi(identifiant);

		if(_nombre_negatif)
		{
			if(int(*_symboleCourant) != Symbole::Type::VALEUR ||
				int(*_symboleCourant) != Symbole::Type::IDENTIFIANT) {

				valeur_id *= -1;
			}
			_nombre_negatif = false;
		}

		return new Valeur(valeur_id);
	}

	if(_nombre_negatif) {
		// on croyait que ce pouvait être un nombre négatif
		// mais on s'est finalement trompé :
		// ce n'est pas une valeur autorisée !
		throw "Un nombre était attendu, mais la chaîne trouvée n'est pas valide";
	}

	// est-ce un mot clé ?

	Symbole* keyword = nullptr;

	if(identifiant == "const") {
		keyword = new Constante();
	} else if (identifiant == "var") {
		keyword = new Variable();
	} else if(identifiant == "lire") {
		keyword = new Lecture();
	} else if(identifiant == "ecrire") {
		keyword = new Affichage();
	}

	if(keyword != nullptr) {
		return keyword;
	}

	// est-ce un identifiant correct ?

	std::string::iterator it = identifiant.begin();
	char premier = *it;

	if(std::isalpha(premier) || premier == '_') {
		
		for(++it ; it != identifiant.end(); ++it) {
			if(!(std::isalpha(*it) || std::isdigit(*it) || *it == '_')) {
				throw "L'identifiant comporte des caractères interdits";
			}
		}

		return new Identifiant(identifiant);
	}

	return nullptr;
}
