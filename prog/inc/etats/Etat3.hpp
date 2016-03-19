#ifndef ETAT3_HPP
#define ETAT3_HPP

#include "Etat.hpp"


class Etat3 : public Etat
{

	public:
		Etat3();
		void transition(Automate* a, Symbole* s);
};

#endif

