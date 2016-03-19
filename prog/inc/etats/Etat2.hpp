#ifndef ETAT2_HPP
#define ETAT2_HPP

#include "Etat.hpp"


class Etat2 : public Etat
{

	public:
		Etat2();
		void transition(Automate* a, Symbole* s);
};

#endif

