#ifndef ETAT9_HPP
#define ETAT9_HPP

#include <iostream>
#include "Etat.hpp"


class Etat9 : public Etat
{
	public:
		Etat9();
		~Etat9();
		void transition(Automate* a, Symbole* s);

};

#endif

