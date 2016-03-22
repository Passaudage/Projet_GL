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

    struct Position {
      int ligne;
      int caractere;
    };
    
    Symbole* lireSymboleCourant();
    Symbole* lireSymboleSuivant();

    /** Renvoie vrai lorsqu'il est encore possible de lire un symbole courant après
      * décalage. Sinon, renvoie faux pour indiquer la fin de la lecture des symboles.
      */
    bool decaler();
    
    void throwError(std::string message);

private:

    Position positionCourante();

    int _ligneCourante;
    int _caractereCourant;
    Position _lastPosition;

    std::ifstream _fichierSource;

    Symbole* _symboleCourant;

    std::queue<Symbole*> _fileSymboles;
    std::queue<Position> _filePositions;

    Symbole* _delimiteurSuivant;
    bool _nombre_negatif;
    bool _renvoie_negatif;
    bool _debut_mot;
    
    Symbole* lire_decaler();
    /** Lit le prochain caractère. Si celui-ci correspond à un délimiteur,
      * le symbole correspondant est retourné, 
      *
      */
    Symbole* lire_delimiteur(char& caractere);

    Symbole* lire_identifiant(std::string& identifiant);
};

#endif