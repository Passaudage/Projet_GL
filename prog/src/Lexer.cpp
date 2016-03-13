#include <string>
#include <iostream>

#include <sstream>

#include <exception>

#include "Lexer.hpp"
#include "Symbole.hpp"


// #### Constructeur et destructeur #### //
Lexer::Lexer(std::string & nomFichier)
{	
	_fichierSource.open(nomFichier);

	if(_fichierSource.good()) {

	} else {
		/* TODO : faire mieux comme message et gestion des erreurs */
		throw std::exception();
	}

	_symboleCourant = lire_decaler();
	_symboleSuivant = lire_decaler();
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

void Lexer::decaler()
{
	_symboleCourant = _symboleSuivant;
	_symboleSuivant = lire_decaler();
}

// #### Privée #### //

Symbole* Lexer::lire_decaler()
{
	Symbole* symboleCourant = nullptr;
	char caractere;

	if(!_fichierSource.get(caractere)) {
		std::cerr << "Plus rien à lire" << std::endl;
		return nullptr;
	}

	// Ici on lit les caractères pour attribuer à
	// symboleCourant le symbole effectif.

	// D'abord les symboles simples

	switch(caractere) {
		case ',':
			//symboleCourant = new Virgule();
			break;
		case ';':
			//symboleCourant = new PointVirgule();
			break;
		default:
			// traitement des expressions plus "compliquées"
			// TODO : tokenizer (séparer grâce aux espaces)
			break;
	}

	return symboleCourant;
}

void Lexer::reduction()
{
	// TODO
}

 