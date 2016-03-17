#ifndef ETAT1_HPP
#define ETAT1_HPP

#include <iostream>
#include "Etat.hpp"


class Etat1 : public Etat
{
	public:
		Etat1();
		~Etat1();
		void transition(Automate* a, Symbole* s);

};

#endif

