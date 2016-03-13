#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Lexer.h"
#include "Symbole.h"

using namespace std;

// #### Constructeur et destructeur #### //
Lexer::Lexer(string & nomFichier)
{
	fstream fichierSource;
	fichierSource.open(nomFichier.c_str());

	stringstream stream;
	stream << fichierSource.rdbuf();
	contenuFichier = stream.str();

	fichierSource.close();

	ligneCourante = 1;
	carCourant = 1;
}

Lexer::~Lexer()
{
	delete symboleCourant;
}

// #### Surcharge #### //
std::ostream& operator << (std::ostream& os, const Lexer& lex)  
{  
    os << lex.getContenu();
    return os;  
} 

// #### Publique #### //
void Lexer::decalage()
{
	symboleCourant = NULL;
}

string& Lexer::getContenu()
{
	return contenuFichier;
}

Symbole * Lexer::getSymbole()
{
	// TODO
	return NULL;
}

// #### Privée #### //
void Lexer::reduction()
{
	// TODO
}

 