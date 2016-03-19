#ifndef ETAT7_HPP
#define ETAT7_HPP

#include <iostream>
#include "Etat.hpp"


class Etat7 : public Etat
{
	public:
		Etat7();
		void transition(Automate* a, Symbole* s);

};

#endif

