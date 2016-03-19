#ifndef ETAT16_HPP
#define ETAT16_HPP

#include <iostream>
#include "Etat.hpp"


class Etat16 : public Etat
{
	public:
		Etat16();
		void transition(Automate* a, Symbole* s);
};

#endif

