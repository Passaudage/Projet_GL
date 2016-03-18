#ifndef ETAT15_HPP
#define ETAT15_HPP

#include <iostream>
#include "Etat.hpp"


class Etat15 : public Etat
{
	public:
		Etat15();
		~Etat15();
		void transition(Automate* a, Symbole* );

};

#endif