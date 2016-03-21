#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <fstream>
#include <queue>

class Symbole;

class Lexer
{
public:
    Lexer(std::string const& nomFichier);
    ~Lexer();
    
    //friend std::ostream& operator<<(std::ostream& os, const Lexer& lex);
    
    Symbole* lireSymboleCourant();
    Symbole* lireSymboleSuivant();

    /** Renvoie vrai lorsqu'il est encore possible de lire un symbole courant après
      * décalage. Sinon, renvoie faux pour indiquer la fin de la lecture des symboles.
      */
    bool decaler();
    
    std::string getLigneColonneCourante();
    void throwError(std::string message);

private:
    int _ligneCourante;
    int _caractereCourant;

    std::ifstream _fichierSource;

    Symbole* _symboleCourant;
    //Symbole* _symboleSuivant;

    std::queue<Symbole*> _fileSymboles;

    Symbole* _delimiteurSuivant;
    bool _nombre_negatif;
    
    Symbole* lire_decaler();
    /** Lit le prochain caractère. Si celui-ci correspond à un délimiteur,
      * le symbole correspondant est retourné, 
      *
      */
    Symbole* lire_delimiteur(char& caractere);

    Symbole* lire_identifiant(std::string& identifiant);
};

#endif