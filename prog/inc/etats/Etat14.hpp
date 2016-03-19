#ifndef ETAT14_HPP
#define ETAT14_HPP

#include "Etat.hpp"

class Etat14 : public Etat
{
	public:
		Etat14();
		void transition(Automate* a, Symbole* );

};

#endif

