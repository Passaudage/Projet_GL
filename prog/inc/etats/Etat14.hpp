#ifndef ETAT14_HPP
#define ETAT14_HPP

#include <iostream>
#include "Etat.hpp"


class Etat14 : public Etat
{
	public:
		Etat14();
		~Etat14();
		void transition(Automate* a, Symbole* s);

};

#endif

