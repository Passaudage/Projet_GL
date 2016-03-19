#ifndef ETAT10_HPP
#define ETAT10_HPP

#include <iostream>
#include "Etat.hpp"


class Etat10 : public Etat
{
	public:
		static Etat10* getInstance();

	private:
		static Etat10 m_instance;
		Etat10();
		void transition(Automate* a, Symbole* s);

};

#endif

