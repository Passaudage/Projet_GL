#ifndef ETAT16_HPP
#define ETAT16_HPP

#include <iostream>
#include "Etat.hpp"


class Etat16 : public Etat
{
	public:
		static Etat16* getInstance();

	private:
		static Etat16 m_instance;
		Etat16();
		void transition(Automate* a, Symbole* s);
};

#endif

