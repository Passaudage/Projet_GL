#ifndef LEXER_H
#define LEXER_H

#include "Symbole.h"

#include <string>
#include <vector>

using namespace std;

class Lexer
{
public:
    Lexer(string & nomFichier);
    ~Lexer();
    
    friend ostream& operator<<(ostream& os, const Lexer& lex);
    
    Symbole *  getSymbole();
    void decalage();
    string& getContenu();
             
    
private: 
	int ligneCourante;
    int carCourant;
    string contenuFichier;
    Symbole * symboleCourant;
    
    void reduction();
    
};

#endif