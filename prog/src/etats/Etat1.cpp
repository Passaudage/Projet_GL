#include <iostream>

#include "etats/Etat1.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "etats/Etat2.hpp"
#include "etats/Etat10.hpp"
#include "etats/Etat3.hpp"
#include "etats/Etat4.hpp"
#include "etats/Etat8.hpp"
#include "etats/Etat5.hpp"
#include "etats/Etat7.hpp"

Etat1::Etat1()
{
}

Etat1 Etat1::m_instance = Etat1();

Etat1* Etat1::getInstance(){
	return &m_instance;
}

void Etat1::transition(Automate* a, Symbole* s)
{
#ifdef MAP
	std::cout << "Etat1" << std::endl;
#endif
	switch(*s){
		case Symbole::INSTRUCTIONS:
			a->pushEtat(Etat2::getInstance());
			break;
		case Symbole::INSTRUCTION:
		//OK
			//~ a->pushEtat(new Etat10());
			a->pushEtat(Etat10::getInstance());
			break;
		case Symbole::VARIABLE:
		//OK
			a->pushEtat(Etat3::getInstance());
			a->decaler();
			break;
		case Symbole::CONSTANTE:
		//OK
			//~ a->pushEtat(new Etat4());
			a->pushEtat(Etat4::getInstance());
			a->decaler();
			break;
		case Symbole::IDENTIFIANT:
			a->pushSymbole(s);
			//~ a->pushEtat(new Etat8());
			a->pushEtat(Etat8::getInstance());
			a->decaler();
			break;
		case Symbole::LECTURE:
		//OK
			//~ a->pushEtat(new Etat5());
			a->pushEtat(Etat5::getInstance());
			a->decaler();
			break;
		case Symbole::AFFICHAGE:
		//OK
			//~ a->pushEtat(new Etat7());
			a->pushEtat(Etat7::getInstance());
			a->decaler();
			break;
		default:
			throw "Erreur, lecture non conforme à la grammaire ! "; 
			break;
	}
}
