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
    void decaler();

private:
    std::ifstream _fichierSource;

    Symbole* _symboleCourant;
    Symbole* _symboleSuivant;
    
    Symbole* lire_decaler();

    void reduction();
};

#endif