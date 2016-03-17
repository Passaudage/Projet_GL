#ifndef ETAT12_HPP
#define ETAT12_HPP

#include <iostream>
#include "Etat.hpp"


class Etat12 : public Etat
{
	public:
		Etat12();
		~Etat12();
		void transition(Automate* a, Symbole* s);

};

#endif

