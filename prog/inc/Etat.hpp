#ifndef ETAT_HPP
#define ETAT_HPP

#include "Automate.hpp"
#include "Symbole.hpp"

class Etat 
{
	public:
		Etat();
		virtual ~Etat();
		virtual void transition(Automate* a, Symbole* s) = 0;
};

#endif
