#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <fstream>
#include <queue>

class Symbole;

/*
 * Lexer permettant de lire le flux d'entrée (fichier texte passé en argument)
 * et d'obtenir une suite de symboles terminaux. La lecture et le décalage
 * sont des opérations indépendantes et il est possible d'avoir accès au 
 * symbole suivant le symbole courant.
 */
class Lexer
{
public:
    Lexer(std::string const& nomFichier);
    ~Lexer();

    struct Position {
      int ligne;
      int caractere;
    };

    /*
     * Permet la lecture des symboles correspondants.
     * Attention : la lecture ne provoque aucun décalage.
     */
    Symbole* lireSymboleCourant();
    Symbole* lireSymboleSuivant();

    /* 
     * Avance la tête de lecture de manière à lire le prochain symbole.
     * Renvoie vrai lorsqu'il est encore possible de lire un symbole courant après
     * décalage. Sinon, renvoie faux pour indiquer la fin de la lecture des symboles.
     */
    bool decaler();
    
private:

    Position positionCourante();

    int _ligneCourante;
    int _caractereCourant;
    Position _lastPosition;

    std::ifstream _fichierSource;

    Symbole* _symboleCourant;

    std::queue<Symbole*> _fileSymboles;
    std::queue<Position> _filePositions;

    bool _nombre_negatif;
    bool _renvoie_negatif;
    bool _debut_mot;

    Symbole* lire_decaler();

    /* 
     * Renvoie le symbole correspondant au délimiteur si caractere en est effectivement
     * un. De manière à lire symbole d'affectation :=, il est possible qu'un caractère
     * supplémentaire soit lu dans le flux de fichier.
     */
    Symbole* lire_delimiteur(char& caractere);

    Symbole* lire_identifiant(std::string& identifiant);
};

#endif
