#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <fstream>

class Symbole;

class Lexer
{
public:
    Lexer(std::string & nomFichier);
    ~Lexer();
    
    //friend std::ostream& operator<<(std::ostream& os, const Lexer& lex);
    
    Symbole* lireSymboleCourant();
    Symbole* lireSymboleSuivant();

    /** Renvoie vrai lorsqu'il est encore possible de lire un symbole courant après
      * décalage. Sinon, renvoie faux pour indiquer la fin de la lecture des symboles.
      */
    bool decaler();

private:
    std::ifstream _fichierSource;

    Symbole* _symboleCourant;
    Symbole* _symboleSuivant;

    Symbole* _delimiteurSuivant;
    
    Symbole* lire_decaler();
    /** Lit le prochain caractère. Si celui-ci correspond à un délimiteur,
      * le symbole correspondant est retourné, 
      *
      */
    Symbole* lire_delimiteur(char& caractere);

    Symbole* lire_identifiant(std::string& identifiant);
};

#endif