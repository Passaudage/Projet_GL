#ifndef ETAT7_HPP
#define ETAT7_HPP

#include <iostream>
#include "Etat.hpp"


class Etat7 : public Etat
{
	public:
		static Etat7* getInstance();

	private:
		static Etat7 m_instance;
		Etat7();
		void transition(Automate* a, Symbole* s);

};

#endif

