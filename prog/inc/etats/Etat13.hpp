#ifndef ETAT13_HPP
#define ETAT13_HPP

#include "Etat.hpp"


class Etat13 : public Etat
{
	public:
		Etat13();
		void transition(Automate* a, Symbole* s);

};

#endif

