#ifndef ETAT_HPP
#define ETAT_HPP

#include "Automate.hpp"
#include "Symbole.hpp"

class Etat 
{
	public:
		~Etat();
		virtual void transition(Automate* a, Symbole* s);
};
#endif 	