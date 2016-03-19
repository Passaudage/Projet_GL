#ifndef ETAT5_HPP
#define ETAT5_HPP

#include "Etat.hpp"

class Etat5 : public Etat
{
	public:
		Etat5();
		void transition(Automate* a, Symbole* s);
};

#endif

