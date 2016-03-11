#ifndef ETAT0_HPP
#define ETAT0_HPP

#include <stdio>
#include "Etat.hpp"

class Etat0 : public Etat
{

	public:
		Etat0()
		void transition(Automate* a, Symbole* s);
};

#endif

