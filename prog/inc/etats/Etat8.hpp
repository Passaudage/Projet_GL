#ifndef ETAT8_HPP
#define ETAT8_HPP

#include <iostream>
#include "Etat.hpp"


class Etat8 : public Etat
{
	public:
		Etat8();
		~Etat8();
		void transition(Automate* a, Symbole* s);

};

#endif

