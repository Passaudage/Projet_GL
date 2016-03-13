#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>

using namespace std;

class Symbole;

class Lexer
{
public:
    Lexer(string & nomFichier);
    ~Lexer();
    
    friend ostream& operator<<(ostream& os, const Lexer& lex);
    
    Symbole* getSymbole();
    void decalage();
    string const& getContenu() const;     
    
private: 
	int ligneCourante;
    int carCourant;
    string contenuFichier;
    Symbole* symboleCourant;
    
    void reduction();
};

#endif