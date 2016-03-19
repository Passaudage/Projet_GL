#ifndef ETAT8_HPP
#define ETAT8_HPP

#include "Etat.hpp"

class Etat8 : public Etat
{
	public:
		Etat8();
		void transition(Automate* a, Symbole* s);
};

#endif

