/*************************************************************************
                           SymbolesTerminaux  -  description
                             -------------------
    début                : dim. 13 mars 2016
*************************************************************************/

#ifndef SYMBOLESTERMINAUX_H
#define SYMBOLESTERMINAUX_H

//--------------------------------------------------- Interfaces utilisées
#include "Symbole.hpp"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <SymboleTerminal>
// Wrapper templatisé des symboles terminaux
//
//------------------------------------------------------------------------ 

template<Symbole::Type S>
class SymboleTerminal : public Symbole
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs
    SymboleTerminal& operator=(const SymboleTerminal & unSymboleTerminal) = delete;

//-------------------------------------------- Constructeurs - destructeur
    SymboleTerminal(const SymboleTerminal & unSymboleTerminal) = delete;

    SymboleTerminal():Symbole(S){};
	
	virtual ~SymboleTerminal(){};
//------------------------------------------------------------------ PRIVE 
};

//----------------------------------------- Types dépendants de <SymboleTerminal>

typedef SymboleTerminal<Symbole::Type::PARENTHESE_OUV> ParentheseOuvrante;
typedef SymboleTerminal<Symbole::Type::PARENTHESE_FER> ParentheseFermante;
typedef SymboleTerminal<Symbole::Type::POINT_VIR> PointVirgule;
typedef SymboleTerminal<Symbole::Type::VIRGULE> Virgule;
typedef SymboleTerminal<Symbole::Type::AFFECTATION> Affectation;
typedef SymboleTerminal<Symbole::Type::EGAL> Egal;

typedef SymboleTerminal<Symbole::Type::CONSTANTE> Constante;
typedef SymboleTerminal<Symbole::Type::VARIABLE> Variable;
typedef SymboleTerminal<Symbole::Type::LECTURE> Lecture;
typedef SymboleTerminal<Symbole::Type::AFFICHAGE> Affichage;

class OperateurMult : public SymboleTerminal<Symbole::Type::OPERATEUR_MUL>
{
public:
//----------------------------------------------------- Méthodes publiques
	bool estMultiplie();
//-------------------------------------------- Constructeurs - destructeur
	OperateurMult(bool multiplie);
protected:
	bool _multiplie;
};

class OperateurAdd : public SymboleTerminal<Symbole::Type::OPERATEUR_ADD>
{
public:
//----------------------------------------------------- Méthodes publiques
	bool estAddition();
//-------------------------------------------- Constructeurs - destructeur
	OperateurAdd(bool addition);
protected:
	bool _addition;
};

#endif // SYMBOLETERMINAUX_H

