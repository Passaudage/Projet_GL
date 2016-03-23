#ifndef SYMBOLE_HPP
#define SYMBOLE_HPP

#include "Lexer.hpp"

class Symbole
{
public:
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

	// Surcharge permettant de faire un switch
	// sur un objet Symbole
	operator int();

	virtual ~Symbole();

	void setType(Type symboleType);
	void setPosition(Lexer::Position position);

	Lexer::Position getPosition();

	int getLigne();
	int getCaractere();
	

protected:

	Type _symboleType;

	Lexer::Position _position;

private:

};

#endif
