#ifndef ETAT17_HPP
#define ETAT17_HPP

#include <iostream>
#include "Etat.hpp"


class Etat17 : public Etat
{
	public:
		Etat17();
		~Etat17();
		void transition(Automate* a, Symbole* s);

};

#endif

