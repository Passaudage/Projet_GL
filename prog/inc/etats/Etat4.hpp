#ifndef ETAT4_HPP
#define ETAT4_HPP

#include "Etat.hpp"


class Etat4 : public Etat
{

	public:
		Etat4();
		void transition(Automate* a, Symbole* s);
};

#endif

