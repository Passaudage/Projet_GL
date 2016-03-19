#ifndef ETAT6_HPP
#define ETAT6_HPP

#include "Etat.hpp"


class Etat6 : public Etat
{
	public:
		Etat6();
		void transition(Automate* a, Symbole* );
};

#endif
