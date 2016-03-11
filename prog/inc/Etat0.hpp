#ifndef ETAT0_HPP
#define ETAT0_HPP

#include <iostream>
#include "Etat.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"

class Etat0 : public Etat
{

	public:
		Etat0();
		~Etat0();
		void transition(Automate* a, Symbole* s);

};

#endif

