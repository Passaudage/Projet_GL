#ifndef ETAT11_HPP
#define ETAT11_HPP

#include <iostream>
#include "Etat.hpp"


class Etat11 : public Etat
{
	public:
		static Etat11* getInstance();

	private:
		static Etat11 m_instance;
		Etat11();
		void transition(Automate* a, Symbole* );

};

#endif
