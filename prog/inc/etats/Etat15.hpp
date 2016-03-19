#ifndef ETAT15_HPP
#define ETAT15_HPP

#include <iostream>
#include "Etat.hpp"


class Etat15 : public Etat
{
	public:
		static Etat15* getInstance();

	private:
		static Etat15 m_instance;
		Etat15();
		void transition(Automate* a, Symbole* );

};

#endif
