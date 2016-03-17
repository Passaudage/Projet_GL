#ifndef ETAT10_HPP
#define ETAT10_HPP

#include <iostream>
#include "Etat.hpp"


class Etat10 : public Etat
{
	public:
		Etat10();
		~Etat10();
		void transition(Automate* a, Symbole* s);

};

#endif

