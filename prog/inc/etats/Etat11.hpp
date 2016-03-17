#ifndef ETAT11_HPP
#define ETAT11_HPP

#include <iostream>
#include "Etat.hpp"


class Etat11 : public Etat
{
	public:
		Etat11();
		~Etat11();
		void transition(Automate* a, Symbole* s);

};

#endif