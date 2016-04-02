#ifndef SYMBOLE_HPP
#define SYMBOLE_HPP

#include "Lexer.hpp"

class Symbole
{
public:
	/*
	 * Regroupe l'ensemble des types de symboles existants.
	 */
	enum Type {
		// Symboles non terminaux
		PROGRAMME,
		DECLARATIONS,
		DECLARATION_VAR,
		DECLARATION_CON,
		INSTRUCTIONS,
		INSTRUCTION,
		EXPRESSION,
		TERME,
		FACTEUR,

		// Symboles terminaux
		PARENTHESE_OUV,
		PARENTHESE_FER,
		OPERATEUR_MUL,
		OPERATEUR_ADD,
		POINT_VIR,
		VIRGULE,
		EGAL,
		LECTURE,
		AFFICHAGE,
		AFFECTATION,
		VALEUR,
		IDENTIFIANT,
		VARIABLE,
		CONSTANTE,
		
		FINDEFLUX
	};

	Symbole(Type symboleType);
	virtual ~Symbole();

	/*
	 * Permet la destruction correcte du symbole,
	 * utile pour éviter les memleaks.
	 */
	virtual void deletePropre();

	/*
	 * Surcharge permettant l'application d'un switch au symbole.
	 * Renvoie le type courant du symbole.
	 * Attention : ce type peut diférer de celui attribué lors de
	 * la construction de l'objet.
	 * cf : Symbole::setType et Symbole::getInitType()
	 */
	operator int();

	/*
	 * Utile lors du parcours des états pour changer
	 * le type du symbole.
	 */
	void setType(Type symboleType);

	/*
	 * Renvoie le type du symbole tel qu'il était à sa construction.
	 */
	int getInitType();

	/*
	 * Gère la position du symbole.
	 */
	void setPosition(Lexer::Position position);
	Lexer::Position getPosition();

	int getLigne();
	int getCaractere();

	

protected:

	Type _symboleType;
	Type _initType;

	Lexer::Position _position;
};

#endif
